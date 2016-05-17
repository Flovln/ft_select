/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:00:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/17 18:19:22 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
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
	int				flag;
	int				select;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_term
{
	char			**ret_key;
	int				col_nb;
	int				row_nb;
	int				elem_nb;
	int				max_len;
	int				fd;
	struct winsize	win;
	struct termios	*term_s;
	struct termios	*term_cpy;
	t_lst			*list;
}					t_term;

int					init_term_data(t_term *term);
int					reset_term_data(t_term *term);
int					my_putchar(int c);
void				arg_in_list(t_term *term, char **av);
void				manage_keycodes(t_term *term, char buffer[5]);
void				do_display(t_lst *node);
int					list_remove_node(t_lst **head);
void				manage_arrows(t_term *term, char buffer[5]);
void				clear_window();
void				manage_signals(void);
void				figure_sig_id(int id);
t_term				*init_struct(void);
void				print_list(t_term *term);
int					display_columns(t_term *term, int col_pos, int i);
void				get_size_info(t_term *term);
void				list_push_node(t_lst **head, t_lst *new_node);
t_lst				*create_node(char **av);
void				free_list(t_term *term);
#endif
