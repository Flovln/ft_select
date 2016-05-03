/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:56:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/03 15:25:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			print_list(t_lst **head) // test
{
	t_lst *tmp;

	tmp = *head;
	ft_putendl("----> list <----");
	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

t_lst	*create_node(char **av)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = ft_strdup(*av);
	//	new->prev = 
	new->next = NULL;
	return (new);
}

void	list_push_node(t_lst **head, t_lst *new_node)
{
	t_lst *cur;

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
