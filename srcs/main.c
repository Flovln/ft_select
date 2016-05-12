/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/12 17:56:51 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			clear_window()
{
//	tputs(tgetstr("rc", NULL), 1, my_putchar); //restores cursor's saved position
//	tputs(tgetstr("cd", NULL), 1, my_putchar); //erases until screen's end
	tputs(tgetstr("cl", NULL), 1, my_putchar);
}

void			print_list(t_lst *node)
{
	while (node)
	{
		do_display(node);
		node = node->next;
	}
}

static int		get_keycode(t_term *term)
{
	char buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
		return (1);
	manage_keycodes(term, buffer);
	clear_window();
	print_list(term->list);
	return (0);
}

static int		ft_select(char **av, t_term *term)
{
	tputs(tgetstr("cr", NULL), 1, my_putchar); // chariot return
	tputs(tgetstr("sc", NULL), 1, my_putchar); // save cursor's current position
	arg_in_list(term, av);
	clear_window();
	print_list(term->list);
	while (1)
	{
		//get_screen_size(term);
		if (get_keycode(term) == 1)
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_term	*term;

	term = init_struct();
	manage_signals();
	if (ac < 2)
	{
		ft_putendl_fd("Error: wrong usage", 2);
		exit (1);
	}
	if (init_term_data(term) == -1)
		return (-1);
	if (ac > 1)
		ft_select(av + 1, term);
	if (reset_term_data(term) == -1)
		return (-1);
	return (0);
}
