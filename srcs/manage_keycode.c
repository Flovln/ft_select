/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:08:58 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/10 12:02:19 by fviolin          ###   ########.fr       */
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

static t_select	*create_node_select(char *str)
{
	t_select *new;

	if (!(new = malloc(sizeof(t_select))))
		return (NULL);
	new->content = ft_strdup(str);
	new->next = NULL;
	return (new);
}

static void		list_push_select(t_select **head, t_select *new_node)
{
	t_select *cur;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
}

static void		validate_selection(t_term *term)
{
	t_lst		*tmp;
	t_select	*cur;

	tmp = term->list;
	cur = term->list_select;
	while (tmp)
	{
		if (tmp->select == 1)
			list_push_select(&term->list_select, create_node_select(tmp->content));
		tmp = tmp->next;
	}
	clear_window();
	reset_term_data(*term);
	while (cur)
	{
		ft_putstr_fd(cur->content, 1);
		ft_putchar_fd(' ', 1);
		cur = cur->next;
	}
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
			exit (0);
		}
	}
	else if (BUFFER == RET_KEY)
		validate_selection(term);
}
