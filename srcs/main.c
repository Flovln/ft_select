/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/17 18:28:18 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int		check_win_size(t_term *term)
{
	int nb_col;

	if (term->row_nb == 1)
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		ft_putendl_fd("window size too small", 1);
		return (1);
	}
	nb_col = (term->elem_nb / (term->row_nb - 1));
	if (nb_col == 0)
		nb_col = 1;
	if (((term->row_nb - 1) * nb_col) < term->elem_nb)
		nb_col++;
	if (((term->max_len + 2) * nb_col) > term->col_nb)
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		ft_putendl_fd("window size too small", 1);
		return (1);
	}
	return (0);
}

void			print_list(t_term *term)
{
	t_lst	*tmp;
	int		i;
	int		col_pos;

	tmp = term->list;
	i = 0;
	col_pos = -1;
	get_size_info(term);
	if (check_win_size(term))
		return ;
	while (tmp)
	{
		col_pos = display_columns(term, col_pos, i);
		do_display(tmp);
		tmp = tmp->next;
		i++;
	}
}

static int		get_keycode(t_term *term)
{
	char buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
	{
		if (reset_term_data(term) == -1)
			return (-1);
		if (close(term->fd) < 0)
			ft_putendl_fd("Close error", 2);
		free_list(term);
		return (1);
	}
	manage_keycodes(term, buffer);
	return (0);
}

static int		ft_select(char **av, t_term *term)
{
	while (*av)
	{
		list_push_node(&term->list, create_node(av));
		av++;
	}
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("sc", NULL), 1, my_putchar);
	print_list(term);
	while (1)
	{
		if (get_keycode(term) == 1)
			return (1);
		tputs(tgetstr("rc", NULL), 1, my_putchar);
		tputs(tgetstr("cd", NULL), 1, my_putchar);
		print_list(term);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_term	*term;

	term = init_struct();
	manage_signals();
	if (ac < 2)
	{
		ft_putendl_fd("Error: wrong usage", 2);
		exit(1);
	}
	term->fd = open(ttyname(0), O_RDWR);
	if (term->fd == -1)
		return (-1);
	if (init_term_data(term) == -1)
		return (-1);
	if (ac > 1)
		ft_select(av + 1, term);
	return (0);
}
