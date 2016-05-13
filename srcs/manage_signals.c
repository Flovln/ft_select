/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:37:41 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/13 13:36:37 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

//void		do_sig_stop(t_term *term)
void		do_sig_stop()
{
	char	cp[2];
	t_term	*term;

	term = init_struct();
	cp[0] = term->term_s->c_cc[VSUSP];
	cp[1] = '\0';
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tcsetattr(0, TCSANOW, term->term_cpy);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

//void		do_sig_cont(t_term *term)
void		do_sig_cont()
{
	char *term_name;
	t_term	*term;

	term_name = NULL;
	term = init_struct();
	signal(SIGTSTP, do_sig_stop);
//	signal(SIGTSTP, figure_sig_id);
	term->term_s->c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, term->term_s);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	print_list(term);
}
/*
void		figure_sig_id(int id)
{
	t_term *term;

	term = init_struct();
	if (id == SIGTSTP)
		do_sig_stop(term);
	else if (id == SIGCONT)
		do_sig_cont(term);
	else if (id == SIGINT || id == SIGQUIT)
	{
		//free + clear list
		ft_putendl_fd("ctr -c", 2);//test
		sleep(1);
	}
}
*/
void        manage_signals(void)
{
//	signal(SIGTSTP, figure_sig_id); //ctr -z
//	signal(SIGCONT, figure_sig_id); //reprise du processus -> fg
	signal(SIGTSTP, do_sig_stop); //ctr -z
	signal(SIGCONT, do_sig_cont); //reprise du processus -> fg
//	signal(SIGINT, figure_sig_id); //ctr -c
//	signal(SIGQUIT, figure_sig_id); //ctrl -\ -> kill
}
