/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_fgrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:00:20 by hfalmer           #+#    #+#             */
/*   Updated: 2019/05/23 01:58:08 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static char	*fgr_line(int fd)/* creates one line of [16] from file*/
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

static int		fgrl_val(char *fgrl)/* checks if this line is valid. if it's not, just frees*/
{
	int	i;
	int	l;

	l = ft_strlen(fgrl);
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

static int		fgr_int(char *fgrl)/* takes fgrl and turns it to int using bits logic after fgrl_val*/
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

int main(int ac, char **av)/* takes file with 19 good fgrs and turns them into ints*/
{
	int fd;
	int i = -1;
	int fgr[19];
	char *sht;

	fd = open(av[1], O_RDONLY);
	while (++i < 19)
	{
		sht = (char*)(fgr_line(fd));
		if (fgrl_val(sht) != 1)
		{
			//vse huevo, virubay;
		}
		fgr[i] = fgr_int(sht); //upya4ka
		printf("%d\n", fgr[i]);
		if (sht)
			free(sht);
		if (get_next_line(fd, &sht) && sht)
			free(sht);
	}
	close(fd);
	return (0);
}
