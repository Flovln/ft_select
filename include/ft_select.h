/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:00:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/05/03 16:10:53 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // printf for tests
#include <term.h>
#include <termios.h>
#include <termcap.h>
#include <curses.h>
#include <signal.h>

typedef struct		s_lst
{
	char			*content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_term
{
	char			*type;
	char			buffer[2048];
	int				result;
	t_lst			*list;
}					t_term;

void				list_push_node(t_lst **head, t_lst *new_node);
t_lst				*create_node(char **av);

void				print_list(t_lst **head); //test function
void				reverse_print(t_lst **head); //test function
#endif
