/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_arrows_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:48:14 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/10 09:52:29 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

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

static void		move_left(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
}

static void		move_right(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
}

void			manage_arrows(t_term *term, char buffer[5])
{
	if (BUFFER == UP_KEY)
		move_up(term);
	else if (BUFFER == DOWN_KEY)
		move_down(term);
	else if (BUFFER == LEFT_KEY)
		move_left(term);
	else if (BUFFER == RIGHT_KEY)
		move_right(term);
}
