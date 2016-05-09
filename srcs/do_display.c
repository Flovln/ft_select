/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:04:56 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 12:49:15 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void	do_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(BASIC, 2);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
}

void	do_reverse_video(char *str)
{
	tputs(tgetstr("so", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(BASIC, 2);
	tputs(tgetstr("se", NULL), 1, my_putchar);
}

void	do_underline_reverse(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_putchar);
	tputs(tgetstr("so", NULL), 1, my_putchar);
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(BASIC, 2);
	tputs(tgetstr("se", NULL), 1, my_putchar);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
}
