/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:37:41 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/17 17:39:26 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	do_sig_stop(int sig)
{
	char	cp[2];
	t_term	*term;

	(void)sig;
	term = init_struct();
	cp[0] = term->term_s->c_cc[VSUSP];
	cp[1] = '\0';
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tcsetattr(term->fd, TCSANOW, term->term_cpy);
	signal(SIGTSTP, SIG_DFL);
	ioctl(term->fd, TIOCSTI, cp);
}

static void	do_sig_cont(int sig)
{
	char	*term_name;
	t_term	*term;

	(void)sig;
	term_name = NULL;
	term = init_struct();
	signal(SIGTSTP, do_sig_stop);
	term->term_s->c_lflag &= ~(ECHO | ICANON);
	tcsetattr(term->fd, TCSANOW, term->term_s);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	print_list(term);
}

static void	do_sig_int(int sig)
{
	t_term *term;

	(void)sig;
	term = init_struct();
	tcsetattr(term->fd, TCSANOW, term->term_cpy);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	free_list(term);
	if (close(term->fd) < 0)
		ft_putendl_fd("Close error", 2);
	exit(0);
}

static void	resize_win(int sig)
{
	t_term *term;

	(void)sig;
	term = init_struct();
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	print_list(term);
}

void		manage_signals(void)
{
	signal(SIGTSTP, do_sig_stop);
	signal(SIGCONT, do_sig_cont);
	signal(SIGINT, do_sig_int);
	signal(SIGQUIT, do_sig_int);
	signal(SIGWINCH, resize_win);
}
