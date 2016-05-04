/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/04 11:22:54 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		my_putchar(int c)
{
	return (write(2, &c, 1));
}

int		ft_select(char **av, t_term *term)
{
	term.list = NULL;
	tputs(tgetstr("cr", NULL), 1, my_putchar);
	tputs(tgetstr("sc", NULL), 1, my_putchar);
	while (*av)
	{
		list_push_node(&term.list, create_node(av));
		av++;
	}
	//count_col(term);
	//print
	//stock
	while (1)
	{
		//get_screen_size(term);
		//if (!keyspot (term)
		//		return(0);
	}
	return (0);
}

int		main(int ac, char **av) //, char **env)
{
	t_term	term;

	if (ac < 2)
	{
		ft_putendl_fd("Error: wrong usage", 2);
		exit (1);
	}
	init_term_data(term)
	if (ac > 1)
		ft_select(av + 1, &term);
	//if (!reset_term_data(&term)
	//	return (-1);
	return (0);
}
