/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 03:02:14 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/14 20:38:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <fcntl.h>
#include <stdio.h>/////
#include "../fillit/libft/libft.h"
#include <math.h>
/*
//gnl
t_lsti				*ft_lstinew(void *cont, size_t cont_size, int index);
t_lsti				*ft_lstimap(t_lsti *lst, t_lsti *(*f)(t_lsti *elem));
void				ft_lstidel(t_lsti **alst, void (*del)(void *, size_t));
void				ft_lstidelone(t_lsti **alst, void (*del)(void *, size_t));
void				ft_lstiiter(t_lsti *lst, void (*f)(t_lsti *elem));
void				ft_lstiadd(t_lsti **alst, t_lsti *new);
typedef struct		s_lsti
{
	void			*content;
	size_t			content_size;
	int				index;
	struct s_lsti	*next;
}					t_lsti;
*/
typedef struct		s_fgr
{
	int				fgr_int;
	char			fgr_chr;
	char			*fgr_line;
	struct s_fgr	*next;
}					t_fgr;

# define FGR1 0000 0000 29 0 401 281 57 27 153

int					six(char **map, t_fgr *fgr, int y, int x);//correct placement for non corn fgrs
unsigned int		rev_bit(unsigned char octet);
char				*ft_fgr_line(int fd);// malloc??
t_fgr				*fgr_new(char fgr_chr, char *line);/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
t_fgr				*fgr_lst(char i, char *line, t_fgr *fgr); /*     */
t_fgr				*after_line(int fd, char **line);//, char *LINE);/* \n between figures && no symbols after \0 EOF && EOF after figures */
int					fgrl_xtra_01(char *fgr_line);/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
int					ft_fgr_int(char *fgrl);/* takes fgrl and turns it to int using bits logic after fgrl_val*/
int					int_check(t_fgr *fgr);
t_fgr				*mega_fgr_val(int fd);
int					putin(char **map, t_fgr *fgr, int y, int x);/* puts 1 fgr in map */
int					fgr_count(t_fgr *fgrlst);/* just count fgrs*/
char				**mapc(int flg);/* creates the minimal start map*/
void				map_free(char **map, int fgc);//t_fgr *fgrlst);// huita
char				**map_increaser(t_fgr *fgrlst, char **map, int flg);// flg = iterrator
int     			check_n(int fd);
int 				place(char **map, t_fgr *fgr, int y, int x);//int s);//(int f);
int					four_check(char **map, t_fgr *fgr, int x, int y, int s);
int					check_input_count(char *blc); //check for wrong chars and extra #
int					rcrs(char ***min_map, t_fgr *fgrlst);//recursion /
void				free_fgr(t_fgr **fgr);
void				print_map(char **map);

//forbidden funcs in header>?

#endif
