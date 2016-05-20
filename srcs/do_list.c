/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:56:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/20 10:39:05 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		del_prev_next(t_lst *tmp)
{
	if (tmp->next)
	{
		tmp->next->flag = 1;
		tmp->next->prev = tmp->prev;
	}
	if (tmp->prev)
	{
		if (!tmp->next)
			tmp->prev->flag = 1;
		tmp->prev->next = tmp->next;
	}
}

int				list_remove_node(t_lst **head)
{
	t_lst *tmp;

	tmp = *head;
	while (tmp->flag != 1)
		tmp = tmp->next;
	tmp->flag = 0;
	if (*head == tmp)
	{
		if (!tmp->next)
			return (1);
		*head = tmp->next;
		tmp->next = *head;
		tmp->next->flag = 1;
	}
	del_prev_next(tmp);
	ft_strdel(&(tmp->content));
	free(tmp);
	return (0);
}

t_lst			*create_node(char **av)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = ft_strdup(*av);
	new->flag = 0;
	new->select = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			list_push_node(t_lst **head, t_lst *new_node)
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
