/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:37:41 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/11 16:40:03 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"


/*
static void		init_struct(t_term *term)
{
	term = (t_term *)malloc(sizeof(t_term));
	if (term)
	{
		term->ret_key = NULL;
		term->result = 0;
		term->col_nb = 0;
		term->row_nb = 0;
		term->list = NULL;
	}
	else
		exit(0);
}*/

t_term			*init_struct(t_term *term, int i)
{
	static t_term *tmp;

	tmp = NULL;
	if (i == 0)
		tmp = term;
	return (tmp);
}

static void		sig_stop()
{
	t_term	*term;
	char	cp[2];

	term = NULL;
	term = init_struct(term, 1);
//	printf("sig_stop\n");
//	sleep(1);//test
	cp[0] = term->term_s.c_cc[VSUSP];
	cp[1] = '\0';
	term->term_s.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
//	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tcsetattr(0, TCSANOW, &(term->term_s));
	ioctl(0, TIOCSTI, cp);
//	reset_term_data(term);
}

static void		sig_cont()
{
	t_term	*term;

	term = NULL;
	term = init_struct(term, 1);
	printf("sig_cont\n");
	sleep(1);//test
	term->term_s.c_lflag &= ~(ICANON);
	term->term_s.c_lflag &= ~(ECHO);
	printf("test3\n");
	sleep(1);
	signal(SIGTSTP, do_sig_num);
	printf("test2\n");
	sleep(1);
	tcsetattr(0, TCSANOW, &(term->term_s));
	printf("test4\n");
	sleep(1);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	printf("test5\n");
	sleep(1);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	//resize window if needed
	//check_size if window is too small
}

void			do_sig_num(int sig)
{
	char	*term_name;

	term_name = NULL;
	if (sig == SIGTSTP) //suspension depuis clavier
		sig_stop();
	else if (sig == SIGCONT) // reprise du processus
		sig_cont();
/*	else if (sig == SIGINT || sig == SIGQUIT)
		//clean_list;
	else
	{
		if (!(term_name = getenv("TERM")))
			//clean_list
		if (!(tgetent(term->char *, term)))
			//clean_list
		//tputs("cl");
		print_args(&term->list);
	}	*/
}

void			manage_signals(void)
{
	printf("manage_signals\n");//test
	sleep(1);//test
	signal(SIGTSTP, do_sig_num);
	signal(SIGCONT, do_sig_num);
	signal(SIGQUIT, do_sig_num);
	signal(SIGINT, do_sig_num);
	signal(SIGWINCH, do_sig_num);
}
