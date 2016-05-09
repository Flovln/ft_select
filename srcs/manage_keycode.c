/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:08:58 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 13:18:47 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		do_select(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->flag != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->flag = 0;
	tmp->next->flag = 1;
}

static void		move_down(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->flag != 1)
		tmp = tmp->next;
	tmp->flag = 0;
	if (tmp->next)
		tmp->next->flag = 1;
	else
		term->list->flag = 1;
}

static void		move_up(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->flag != 1)
		tmp = tmp->next;
	tmp->flag = 0;
	if (tmp->prev)
		tmp->prev->flag = 1; 
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->flag = 1; 
	}
}

void			manage_keycodes(t_term *term, char buffer[5])
{
	if (BUFFER == UP_KEY)
		move_up(term);
	else if (BUFFER == DOWN_KEY)
		move_down(term);
	else if (BUFFER == SPACE_KEY)
		do_select(term);
/*  else if (BUFFER == LEFT_KEY)
	//move left
	else if (BUFFER == RIGHT_KEY)*/
	//move right
//	else if (BUFFER == RET_KEY)
	//return choices made w/ space_key
}
