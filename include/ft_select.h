/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:00:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/10 12:08:06 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // printf for tests
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>

# define BUFFER *(unsigned int *)buffer
# define BASIC "\033[00m"
# define YELLOW "\033[1;33m"

typedef enum		e_enum
{
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	RET_KEY = 10,
}					t_enum;

typedef struct		s_lst
{
	char			*content;
	int				len;
	int				flag;
	int				select;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_select
{
	char			*content;
	struct s_select	*next;
}					t_select;

typedef struct		s_term
{
	struct termios	term_s;
//	char			*type;
	char			**ret_key;
	int				result;
	int				col_nb;
	int				row_nb;
	t_lst			*list;
	t_select		*list_select;
}					t_term;

int					init_term_data(t_term term);
int					reset_term_data(t_term term);
int					my_putchar(int c);
void				arg_in_list(t_term *term, char **av);
void				manage_keycodes(t_term *term, char buffer[5]);
void				do_display(t_lst *node);
int					list_remove_node(t_lst **head);
void				manage_arrows(t_term *term, char buffer[5]);
void				clear_window();

void				print_list(t_lst **head); //test function
void				reverse_print(t_lst **head); //test function
#endif
