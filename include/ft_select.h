/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:00:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/08 15:15:47 by fviolin          ###   ########.fr       */
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
	SUP_KEY = 2117294875,
	TAB_KEY = 9,
	HOME_KEY = 4741915,
	END_KEY = 4610843,
	PAGE_UP_KEY = 2117425947,
	PAGE_DOWN_KEY = 2117491483,
	CRTL_A_KEY = 1,
}					t_enum;

typedef struct		s_lst
{
	char			*content;
//	int				len;
//	int				line;
//	int				select;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_term
{
//	char			buffer[2048];
	struct termios	term_s; //contain terminal infos, will be used to change terminal's behavior
	char			*type;
	char			**ret;
	int				result;
	int				col_nb;
	int				row_nb;
	t_lst			*list;
}					t_term;

int					init_term_data(t_term term);
int					reset_term_data(t_term term);
int					my_putchar(int c);
void				arg_in_list(t_term *term, char **av);

void				print_list(t_lst **head); //test function
void				reverse_print(t_lst **head); //test function
#endif
