/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:23:41 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/10 16:23:56 by fviolin          ###   ########.fr       */
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

static void		stock_res(t_term *term)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = term->list;
	while (tmp)
	{
		if (tmp->select == 1)
		{
			term->ret_key[i] = ft_strdup(tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	term->ret_key[i] = 0;
}

static void		validate_selection(t_term *term)
{
	t_lst	*tmp;
	int		count;
	int		i;

	count = 0;
	i = 0;
	tmp = term->list;
	while (tmp)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	term->ret_key = (char **)malloc(sizeof(char *) * (count + 1));
	stock_res(term);
	reset_term_data(*term);
	clear_window();
	while (i < count - 1)
	{
		ft_putstr_fd(term->ret_key[i], 1);
		ft_putchar(' ');
		i++;
	}
	ft_putendl_fd(term->ret_key[i], 1);
	exit(0);
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
			exit(0);
		}
	}
	else if (BUFFER == RET_KEY)
		validate_selection(term);
}
