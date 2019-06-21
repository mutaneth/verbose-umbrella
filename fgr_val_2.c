/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgr_val_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/05/23 03:56:23 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fgr	*fgr_new(char fgr_chr, char *line)/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
{
	t_fgr	*fgr;

	fgr = (t_fgr*)malloc(sizeof(t_fgr));
	fgr->fgr_int = -1;
	fgr->fgr_chr = fgr_chr;
	fgr->fgr_line = ft_strdup(line);
	fgr->next = NULL;
	return (fgr);
}

char	*fgr_line(int fd)/* creates one line of [16] from file*/
{
	char	*tmps;
	char	*fgrl;
	int		i;
	int		len;

	i = -1;
	while (++i < 4 && get_next_line(fd, &tmps) == 1)
	{
		len = ft_strlen(tmps);
		if (len == 4)
			fgrl = ft_strrejoin(tmps, fgrl, -1);
		else
		{
			if (tmps)
				free(tmps);
			return (NULL);
		}
	}
	return (fgrl);
}

int		fgrl_val(char *fgrl)/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
{
	int	i;
	int	l;

	l = ft_strlen(fgrl);
	if (l != 16)
		return (0);
	i = -1;
	while (++i < l)
	{
		if (fgrl[i] != '.' && fgrl[i] != '#')
		{
			free(fgrl);
			return (0);
		}
		if (fgrl[i] == '.')
			fgrl[i] = '0';
		else
			fgrl[i] = '1';
	}
	return (1);
}

int		fgr_int(char *fgrl)/* takes fgrl and turns it to int using bits logic after fgrl_val*/
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

t_fgr	*fgr_lst(int fd)/* makes list of all fgrs from file*/
{// TODO
	char	*tmps;
	char	*sht;
	char	*fgl;
	char	i;
	t_fgr	*fgr_list;

	i = 65;
	while (get_next_line(fd, &tmps) = 1)
	{
		if ()
		while ((fgrl = fgr_line(fd)) && fgrl_val(fgrl) && (++i < 90))
			fgr_list->next = fgr_new(fgr_int(fgrl), (char)i);
	}
	if get_next_line = 1
		return NULL
	return (fgr_list);
}

int		int_val(int )/* checks if there is any bad fgrs in list of ints*/
{}

int		gnl_val(int fd)/* cheks if next line is ok*/
{
	char *tmps;

	if (get_next_line(fd, &tmps) == 1)
	{
		if (ft_strlen(tmps) == 1 && tmps[0] == '\n')
		{
			if (tmps)
				free(tmps);
			return (1);
		}
	}
	if (get_next_line(fd, &tmps) == 0)
	{
		if (tmps)
			free(tmps);
		return (0);
	}
	if (tmps)
		free(tmps);
	return (-1);
}

int		mega_fgr_val(int fd)/* validate the file(fd)*/
{
	int i;
	int fgr[26];
	char *sht;

	i = 0;
	ft_bzero((void*)fgr, 26);
	while (get_next_line(fd, &sht) = 1)
	{
		sht = (char*)(fgr_line(fd));
		if (fgrl_val(sht) != 1)
		{
			if (sht)
				free(sht);
		}
		if (gnl_val(fd) < 0)
			free;
			return 0;
		if (!(gnl_val(fd))
			stop
		fgr[i] = fgr_int(sht); //upya4ka
		if (sht)
			free(sht);
		if (get_next_line(fd, &sht) && sht)
			free(sht);
	}
	return (0);
}
