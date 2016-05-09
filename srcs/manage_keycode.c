/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:08:58 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 10:46:12 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		do_select(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->line_flag != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->line_flag = 0;
	tmp->next->line_flag = 1;
}

static void		move_down(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->line_flag != 1)
		tmp = tmp->next;
	if (tmp->next)
	{
		tmp->line_flag = 0;
		tmp->next->line_flag = 1;
	}
}

static void		move_up(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->line_flag != 1)
		tmp = tmp->next;
	if (tmp->prev)
	{
		tmp->line_flag = 0;
		tmp->prev->line_flag = 1; 
	}
}

void			manage_keycodes(t_term *term, char buffer[5])
{
	if (BUFFER == UP_KEY)
		move_up(term);
	if (BUFFER == DOWN_KEY)
		move_down(term);
/*  else if (BUFFER == LEFT_KEY)
	//move left
	else if (BUFFER == RIGHT_KEY)*/
	//move right
	else if (BUFFER == SPACE_KEY)
		do_select(term);
//	else if (BUFFER == RET_KEY)
	//return choices made w/ space_key
}
