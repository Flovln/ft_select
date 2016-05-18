/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_display__columns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:31:42 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/18 11:43:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		list_size(t_term *term)
{
	int		len;
	int		elem_nb;
	int		max_len;
	t_lst	*tmp;

	elem_nb = 0;
	max_len = 0;
	tmp = term->list;
	while (tmp)
	{
		len = ft_strlen(tmp->content);
		if (len > max_len)
			max_len = len;
		elem_nb++;
		tmp = tmp->next;
	}
	term->elem_nb = elem_nb;
	term->max_len = max_len;
}

void			get_size_info(t_term *term)
{
	ioctl(0, TIOCGWINSZ, &(term->win));
	term->row_nb = term->win.ws_row;
	term->col_nb = term->win.ws_col;
	list_size(term);
}

int				display_columns(t_term *term, int col_pos, int i)
{
	int j;
	int nb_col;
	int nb_max;

	j = 0;
	nb_col = (term->elem_nb / (term->row_nb - 1));
	if (nb_col == 0)
		nb_col = 1;
	if (((term->row_nb - 1) * nb_col) < term->elem_nb)
		nb_col++;
	nb_max = term->row_nb - 1;
	if (i == 0)
		tputs(tgetstr("rc", NULL), 1, my_putchar);
	if (i != 0 && i % (nb_max) == 0)
	{
		col_pos += (term->max_len + 2);
		tputs(tgetstr("rc", NULL), 1, my_putchar);
	}
	while (j++ <= col_pos)
		tputs(tgetstr("nd", NULL), 1, my_putchar);
	return (col_pos);
}
