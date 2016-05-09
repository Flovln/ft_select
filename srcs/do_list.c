/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:56:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 16:14:55 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			print_args(t_lst *node)
{
	while (node)
	{
		if (node->select == 1 && node->flag == 1)
			do_underline_reverse(node->content);
		else if (node->flag == 1)
			do_underline(node->content);
		else if (node->select == 1)
			do_reverse_video(node->content);
		else
			ft_putendl_fd(node->content, 2);
		node = node->next;
	}
}
void			list_remove_node(t_term *term)
{
	t_lst *tmp;

	if (term->list == term->list->next)
	{
		free(term->list);
		// return;
	}
	tmp = term->list;
	if (term->list->line == 1)
		term->list = tmp->next;
//	tmp->flag = 0;
	if (tmp->prev)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->next->flag = 1;
	}
	ft_strdel(&(tmp->content));
	free(tmp);
}

static t_lst	*create_node(char **av)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = ft_strdup(*av);
	new->len = ft_strlen(new->content);
	new->flag = 0;
	new->select = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static void		list_push_node(t_lst **head, t_lst *new_node)
{
	t_lst *cur;

	if (!*head)
	{
		*head = new_node;
		(*head)->flag = 1;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

void			arg_in_list(t_term *term, char **av)
{
	while (*av)
	{
		list_push_node(&term->list, create_node(av));
		av++;
	}
}
