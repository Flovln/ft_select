/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:00:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/04 11:50:54 by fviolin          ###   ########.fr       */
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
	struct termios	term_s;
	char			*type;
	char			**ret;
	int				result;
	int				col_nb;
	int				row_nb;
	t_lst			*list;
}					t_term;

void				list_push_node(t_lst **head, t_lst *new_node);
t_lst				*create_node(char **av);
int					init_term_data(t_term *term);
int					my_putchar(int c);

void				print_list(t_lst **head); //test function
void				reverse_print(t_lst **head); //test function
#endif
