/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:56:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 10:52:33 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			print_args(t_lst *node)
{
	while (node)
	{
		ft_putendl(node->content);
		node = node->next;
	}
}

static t_lst	*create_node(char **av)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = ft_strdup(*av);
	new->len = ft_strlen(new->content);
	/* use to flag the current node we are on with cursor */
	new->flag = 0;
	/* first node will be one, then when we move to the second node, the 1st will 
	 * be 0 and then the 2nd will take value 1, etc..
	 */
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
