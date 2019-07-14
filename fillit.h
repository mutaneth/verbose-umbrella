/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 03:02:14 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/10 18:46:34 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <fcntl.h>
#include <stdio.h>/////
#include "../fillit/libft/libft.h"
#include <math.h>

typedef struct		s_fgr
{
	int				fgr_int;
	char			fgr_chr;
	char			*fgr_line;
	struct s_fgr	*next;
}					t_fgr;

# define FGR1 0000 0000

int six(char **map, t_fgr *fgr, int s);//correct placement for non corn fgrs
unsigned int		rev_bit(unsigned char octet);
char				*ft_fgr_line(int fd);// malloc??
t_fgr				*fgr_new(char fgr_chr, char *line);/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
t_fgr				*fgr_lst(char i, char *line, t_fgr *fgr); /*     */
t_fgr				*after_line(int fd);//, char *LINE);/* \n between figures && no symbols after \0 EOF && EOF after figures */
int					fgrl_xtra_01(char *fgr_line);/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
int					ft_fgr_int(char *fgrl);/* takes fgrl and turns it to int using bits logic after fgrl_val*/
int					int_check(t_fgr *fgr);
t_fgr				*mega_fgr_val(int fd);
int					putin(char **map, t_fgr *fgr, int s);/* puts 1 fgr in map */
int					fgr_count(t_fgr *fgrlst);/* just count fgrs*/
char				**mapc(int flg);/* creates the minimal start map*/
void				map_free(char **map, t_fgr *fgrlst);// huita
char				**map_increaser(t_fgr *fgrlst, char **map, int flg);// flg = iterrator
int     			check_n(int fd);
int 				place(char **map, t_fgr *fgr, int y, int x);//int s);//(int f);
int					four_check(char **map, t_fgr *fgr, int x, int y, int s);
int					check_input_count(char *blc); //check for wrong chars and extra #
int					rcrs(char **min_map, t_fgr *fgrlst, int flg_s);//recursion /

//forbidden funcs in header>?

#endif
