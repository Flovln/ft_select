/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_term_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:21:46 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/12 18:00:09 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_term		*init_struct(void)
{
	static t_term *term;

	if (term)
		return (term);
	if (!(term = (t_term *)malloc(sizeof(t_term))))
		return (NULL);
	term->ret_key = NULL;
	term->result = 0;
	term->col_nb = 0;
	term->row_nb = 0;
	term->term_s = NULL;
	term->term_cpy = NULL;
	term->list = NULL;
	return (term);
}

int			init_term_data(t_term *term)
{
	struct winsize	win;
	struct termios	*term_s;
	struct termios	*term_cpy;

	if (!(term_s = (struct termios *)malloc(sizeof(struct termios))))
		return (-1);
	if (!(term_cpy = (struct termios *)malloc(sizeof(struct termios))))
		return (-1);
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (-1);
	if (tcgetattr(0, term_s) == -1)
		return (-1);
	if (tcgetattr(0, term_cpy) == -1)
		return (-1);
	term->term_s = term_s;
	term->term_cpy = term_cpy;
	term->term_s->c_lflag &= ~(ECHO | ICANON);
	term->term_s->c_cc[VMIN] = 1;
	term->term_s->c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	term->col_nb = win.ws_col;
	term->row_nb = win.ws_row;
	if (tcsetattr(0, 0, term->term_s) == -1)
		return (-1);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	return (0);
}

int			reset_term_data(t_term *term)
{
	term->term_s->c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, term->term_s) == -1)
		return (-1);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	return (0);
}
