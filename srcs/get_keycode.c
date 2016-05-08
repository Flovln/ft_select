/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:08:58 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/08 18:22:42 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		clear_window()
{
	tputs(tgetstr("rc", NULL), 1, my_putchar); //restores cursor's saved position
	tputs(tgetstr("cd", NULL), 1, my_putchar); //erases until screen's ends
}

static void		move_down(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->line_flag != 1) // flag to know where cursor is at the next print list
		tmp = tmp->next;
	tmp->line_flag = 0;
	tmp->next->line_flag = 1;
}

static void		move_up(t_term *term)
{
	t_lst *tmp;

	tmp = term->list;
	while (tmp->line_flag != 1)
		tmp = tmp->next;
	tmp->line_flag = 0;
	tmp->prev->line_flag = 1; 
}

static void		manage_keycode(t_term *term, char buffer[5])
{
	if (BUFFER == UP_KEY)
		move_up(term);
	else if (BUFFER == DOWN_KEY)
		move_down(term);
/*  else if (BUFFER == LEFT_KEY)
	//move left
	else if (BUFFER == RIGHT_KEY)
	//move right
	else if (BUFFER == SPACE_KEY)
	//select element
	else if (BUFFER == RET_KEY)*/
	//return choices made w/ space_key
}

int				get_keycode(t_term *term)
{
	char	buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
		return (1);
	manage_keycode(term, buffer);
	/* test to get key value */
	printf("keycode = |%u|\n", BUFFER); //
	clear_window();
	print_args(term->list); //print the modify list each time an event occurs
	return (0);
}
