/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 03:02:14 by hfalmer           #+#    #+#             */
/*   Updated: 2019/05/17 20:00:43 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <stdio.h>/////
//# include "gnl/get_next_line.h"

typedef struct		s_fgr
{
	int				fgr_int;
	char			fgr_chr;
	char			*fgr_line;
	struct s_fgr	*next;
}					t_fgr;

# define FGR1 0000 0000
char				*ft_fgr_line(int fd);// malloc??
t_fgr				*fgr_new(char fgr_chr, char *line);/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
t_fgr				*fgr_lst(char i, char *line, t_fgr *fgr); /*     */
t_fgr				*after_line(int fd);//, char *LINE);/* \n between figures && no symbols after \0 EOF && EOF after figures */
int					fgrl_xtra_01(char *fgr_line);/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
int					ft_fgr_int(char *fgrl);/* takes fgrl and turns it to int using bits logic after fgrl_val*/
int					int_check(t_fgr *fgr);
t_fgr				*mega_fgr_val(int fd);


#endif
