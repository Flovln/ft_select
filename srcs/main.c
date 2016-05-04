/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:05:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/04 14:07:44 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		my_putchar(int c)
{
	return (write(2, &c, 1));
}
/* test */
void		get_key()
{
	int		ret = 0;
	char	buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);

	printf("keycode = |%u|\n", BUFFER); //test
	ret = tgetnum(buffer);
	printf("ret = |%d|\n", ret); //test
}

int		ft_select(char **av, t_term *term)
{
	tputs(tgetstr("cr", NULL), 1, my_putchar); // chariot return
	tputs(tgetstr("sc", NULL), 1, my_putchar); // save cursor position
	arg_in_list(term, av);
	//count_col(term);
	//print
	//stock
	while (1)
	{
		//get_screen_size(term);
		//if (!keyspot (term)
		//		return(0);
		get_key();
	}
	return (0);
}

int		main(int ac, char **av) //, char **env)
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
	//if (!reset_term_data(&term)
	//	return (-1);
	return (0);
}
