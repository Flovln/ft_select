/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_term_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:21:46 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/08 15:16:02 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		init_term_data(t_term term)
{
	struct winsize win;

	term.result = 0;
//	ft_bzero(term.termbuffer, 2048);
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (-1);
	if (tcgetattr(0, &(term.term_s)) == -1)
		return (-1); // fill struct termios of terminal's possibilities / get changes
	term.term_s.c_lflag &= ~(ICANON); // canonical mode
	term.term_s.c_lflag &= ~(ECHO); //keys pressed won't appear in the terminal anymore
	term.term_s.c_cc[VMIN] = 1; // value min received 
	term.term_s.c_cc[VTIME] = 0; // n time for read return
	term.col_nb = win.ws_col;
	ioctl(0, TIOCGWINSZ, &win); // get window size
	term.row_nb = win.ws_row;
	if (tcsetattr(0, 0, &term.term_s) == -1) //set changes done above
		   return (-1);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	return (0);
}

int		reset_term_data(t_term term)
{
	if (tcgetattr(0, &(term.term_s)) == -1)
		return (-1);
	term.term_s.c_lflag &= ~(ICANON);
	term.term_s.c_lflag &= ~(ECHO);
	if (tcsetattr(0, 0, &term.term_s) == -1)
		return (-1);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	return (0);
}
