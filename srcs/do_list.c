/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:56:10 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/04 14:08:01 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			print_list(t_lst **head) // test
{
	t_lst *tmp;

	tmp = *head;
	ft_putendl("----> print_list <----");
	while (tmp->next)
	{
		printf("cur->content |%s|\n", tmp->content);
		printf("cur->next->content |%s|\n", tmp->next->content);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void			reverse_print(t_lst **head) // test
{
	t_lst *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	ft_putendl("----> reverse_print_list <----");
	while (tmp->prev)
	{
		printf("cur->content |%s|\n", tmp->content);
		printf("cur->prev->content |%s|\n", tmp->prev->content);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}

static t_lst	*create_node(char **av)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = ft_strdup(*av);
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
