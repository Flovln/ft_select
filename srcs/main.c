/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/09 10:03:18 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		my_putchar(int c)
{
	return (write(2, &c, 1));
}

int		ft_select(char **av, t_term *term)
{
	tputs(tgetstr("cr", NULL), 1, my_putchar); // chariot return
	tputs(tgetstr("sc", NULL), 1, my_putchar); // save cursor's current position
	arg_in_list(term, av); // save arguments
	print_args(term->list); //print when we first get in the program
	//count_col(term);
	//stock
	while (1)
	{
		//get_screen_size(term);
		print_list(&term->list);//test
		if(get_keycode(term) == 1)
			break ;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_term	term;

	term.list = NULL;
	if (ac < 2)
	{
		ft_putendl_fd("Error: wrong usage", 2);
		exit (1);
	}
	if (init_term_data(term) == -1)
		return (-1);
	if (ac > 1)
		ft_select(av + 1, &term);
	if (reset_term_data(term) == -1)
		return (-1);
	return (0);
}
