/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:08:58 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/10 09:52:12 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		do_select(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->flag != 1)
		tmp = tmp->next;
	tmp->flag = 0;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	if (tmp->next)
		tmp->next->flag = 1;
	else
		term->list->flag = 1;
}

static void		validate_selection(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
}

void			manage_keycodes(t_term *term, char buffer[5])
{
	manage_arrows(term, buffer);
	if (BUFFER == SPACE_KEY)
		do_select(term);
	else if (BUFFER == DEL_KEY) 
	{
		if (list_remove_node(&term->list) == 1)
		{
			reset_term_data(*term);
			exit (0);
		}
	}
	else if (BUFFER == RET_KEY)
		validate_selection(term);
}
