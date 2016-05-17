/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:23:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/17 16:23:23 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		free_tab(t_term *term)
{
	int i;
	int len;

	if (term->ret_key)
	{
		if (*(term)->ret_key)
		{
			i = 0;
			len = ft_tablen(term->ret_key);
			while (i < len)
			{
				ft_strdel(&(term)->ret_key[i]);
				i++;
			}
		}
		free(term->ret_key);
		term->ret_key = NULL;
	}
}

void			free_list(t_term *term)
{
	t_lst *next;
	t_lst *node;

	node = term->list;
	if (term->ret_key)
		free_tab(term);
	while (node)
	{
		next = node->next;
		if (node->content)
			free(node->content);
		node->flag = 0;
		node->select = 0;
		free(node);
		node = next;
	}
	node = NULL;
}
