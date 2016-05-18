/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1016/05/09 11:04:56 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/18 16:13:30 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				my_putchar(int c)
{
	write(0, &c, 1);
	return (0);
}

static void		do_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd(BASIC, 0);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
}

static void		do_reverse_video(char *str)
{
	tputs(tgetstr("so", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd(BASIC, 0);
	tputs(tgetstr("se", NULL), 1, my_putchar);
}

static void		do_underline_reverse(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_putchar);
	tputs(tgetstr("so", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 0);
	ft_putstr_fd(YELLOW, 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd(BASIC, 0);
	tputs(tgetstr("se", NULL), 1, my_putchar);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
}

void			do_display(t_lst *node)
{
	if (node->select == 1 && node->flag == 1)
		do_underline_reverse(node->content);
	else if (node->flag == 1)
		do_underline(node->content);
	else if (node->select == 1)
		do_reverse_video(node->content);
	else
		ft_putendl_fd(node->content, 0);
}
