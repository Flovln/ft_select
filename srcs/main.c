/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/03 16:14:27 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
/*
int		init_terminal_data()
{
	char	*termtype;
	char	termbuffer[2048];
	int		result;

	ft_bzero(termbuffer, 2048);
	result = 0;
	if (!(termtype = getenv("TERM")))
		return (-1);
	result = tgetent(termbuffer, termtype);
	if (result < 0)
		ft_putendl_fd("Could not access the termcap data base.\n", 2);
	if (result == 0)
	{
		ft_putendl_fd("Terminal type is ", 2);
		ft_putstr_fd(termtype, 2);
		ft_putendl_fd(" is not defined.\n", 2);
	}
	return (0);
}
*/
int		main(int ac, char **av) //, char **env)
{
	t_term	term;

	av++;
	term.list = NULL;
	if (ac < 2)
	{
		ft_putendl_fd("Error: wrong usage", 2);
		exit (1);
	}
	while (*av)
	{
		list_push_node(&term.list, create_node(av));
		av++;
	}
	print_list(&term.list); //test
	reverse_print(&term.list);//test
/*	if (!init_terminal_data())
		printf("test\n");*/
	return (0);
}
