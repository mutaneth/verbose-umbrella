/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/05/23 03:56:23 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
/*  int			check_input_count(char *blc) //check for wrong chars and extra #
{
	int i;
	int sharp;

	i = -1;
//	while (str[++i] && (str[++i] == '\n' || str[++i] == '#' || str[++i] == '.'));
	while (blcstr[++i])
	{
		if (blcstr[i] != '\n' && blcstr[i] != '#' && blcstr[i] != '.')
			return (0);
		sharp = 0;
		if (blcstr[i] == '#' && ++sharp > 4)
			return (0);
	}
	return (1);
}
*/

char			*ft_fgr_line(int fd)// malloc??
{
	int i;
	char *tmp;
	char *fgrl;

	i = -1;
	while(++i < 4  && get_next_line(fd, &tmp) == 1)
	{
		if (ft_strlen(tmp) == 4)
			fgrl = ft_strrejoin(tmp, fgrl, -1);
		else
		{
			if (tmp)
				free(tmp);
			return (NULL);//free fgrl?
		}
	}
	if (i < 4 && get_next_line(fd, &tmp) < 1)
		return (NULL);
			printf("AR");
	return (fgrl);
}

t_fgr			*fgr_new(char fgr_chr, char *line)/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
{
	t_fgr	*fgr;

	fgr = (t_fgr*)malloc(sizeof(t_fgr));
	fgr->fgr_int = -1;
	fgr->fgr_chr = fgr_chr;
	fgr->fgr_line = ft_strdup(line);
	fgr->next = NULL;
	return (fgr);
}

t_fgr			*fgr_lst(char i, char *line, t_fgr *fgr) /*     */
{
	t_fgr *tmp;

	if (!fgr)
		fgr_new(i, line);
	else
	{
		tmp = fgr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = fgr_new(i, line);
	}
	return (fgr);
}

t_fgr			*after_line(int fd)/* \n between figures && no symbols after \0 EOF && EOF after figures */
{
	char	i;
	char	buf[2];//SIZE NEEDED!
	t_fgr	*fgr;
	t_fgr	*tmpf;
	char *line;//line where

	tmpf = fgr;
	i = 'A' - 1;
//	printf("WHYSEGA?"); //SEGAA>>>????
	while ( /* ft_fgr_line(fd) && */ ++i < 'Z') //if
	{
		tmpf = fgr_lst(i, line, fgr);
		read(fd, buf, 1);
//		buf[1] = '\0';
		printf("buf=%s", buf);
//		printf("buf[0] =%c", buf[0]);
		if (buf[0] == '\0')
			break ;
		if (buf[0] != '\n')
			return (NULL);//free 
	}
	printf("buf[0] =%c\n", buf[0]);
	if ( /* buf[0] && */buf[0] == '\0' && read(fd, buf, 1) == 1)
		return (0);
	else
		return (NULL); // if null ? else null?
/*	if (ft_fgr_line(fd))
		return (NULL); */
	return (fgr);
}

int		fgrl_xtra_01(char *fgr_line)/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
{
	int	i;
	int	l;

	l = ft_strlen(fgr_line);
	if (l != 16)
		return (0);
	i = -1;
	while (++i < l)
	{
		if (fgr_line[i] != '.' && fgr_line[i] != '#')
			//free(fgr_l);
			return (0);
		if (fgr_line[i] == '.')
			fgr_line[i] = '0';
		else
			fgr_line[i] = '1';
	}
	return (1);
}

int		ft_fgr_int(char *fgrl)/* takes fgrl and turns it to int using bits logic after fgrl_val*/
{
	int	fgr_int;
	int	frst;
	int	i;

	fgr_int = 0;
	frst = -1;
	i = -1;
	while (++i < 16)
	{
		if (frst == -1)
			if (fgrl[i] - '0' == 1)
				frst = i;
		if (frst != -1)
			fgr_int |= (fgrl[i] - '0') << (i - frst);
	}
	return (fgr_int);
}

int			int_check(t_fgr *fgr)
{
	t_fgr	*tmp;

	tmp = fgr;
	while (tmp->next)// 1 elem?
	{
		if (!(tmp->fgr_int == 4369 || tmp->fgr_int == 15 || tmp->fgr_int == 547 || 
		tmp->fgr_int == 29 || tmp->fgr_int == 785 || tmp->fgr_int == 23 || 
		tmp->fgr_int == 275 || tmp->fgr_int == 71 || tmp->fgr_int == 401 || 
		tmp->fgr_int == 113 || tmp->fgr_int == 51 || tmp->fgr_int == 99 || 
		tmp->fgr_int == 153 || tmp->fgr_int == 57 || tmp->fgr_int == 305 || 
		tmp->fgr_int == 39 || tmp->fgr_int == 281 || tmp->fgr_int == 27 || 
		tmp->fgr_int == 561))
			 return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_fgr			*mega_fgr_val(int fd)
{
	t_fgr *ok_fgr;
	t_fgr *tmp;
	char *line;

	ok_fgr = after_line(fd);//, &line);
/* 	tmp = ok_fgr;
	printf("OLEAFTEROUT");
	while (tmp->next)
	{
		if (!(fgrl_xtra_01(tmp->fgr_line)))
			return (NULL);// free
		tmp->fgr_int = ft_fgr_int(tmp->fgr_line);
		tmp = tmp->next;
	}
	tmp = ok_fgr;
	if (!(int_check(tmp)))
		return (NULL);// free
*/	return (ok_fgr);
}