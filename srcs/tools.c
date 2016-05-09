/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:32:53 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 10:52:09 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

/* temporary file stocking tools function for testing while coding */

void	print_list(t_lst **head)
{
	t_lst *tmp;

	tmp = *head;
	ft_putendl("-----> print_list <-----");
	while (tmp)
	{
		printf("cur->content |%s|  ", tmp->content);
		printf(" select |%d|  ", tmp->select);
		printf("flag |%d|\n", tmp->flag);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	ft_putendl("-----> print_list end <-----");
	ft_putchar('\n');
}

void	reverse_print(t_lst **head)
{
	t_lst *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	ft_putendl("-----> reverse_print <-----");
	while (tmp->prev)
	{
		printf("cur->content |%s|\n", tmp->content);
		printf("cur->next->content |%s|\n", tmp->next->content);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	ft_putendl("-----> reverse_print end<-----");
	ft_putchar('\n');
}
