/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:00:02 by ddratini          #+#    #+#             */
/*   Updated: 2019/06/21 20:04:20 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

int main(int ac, char **av)
{
	t_fgr *r;
//	int fd;
//	if (ac == 2)
int	fd = open (av[1], O_RDONLY);
	printf("fd=%d-\n", fd);
	/* printf("figure=\n%s",*/ r = mega_fgr_val(fd);
//	printf("r=\n%s", r->fgr_line);
	close(fd);
	return (0);
}
/* from VALI */
int main(int ac, char **av)// huge main
{
	t_fgr *r;
//	int fd;
	if (ac == 2)
	{
		int	fd = open (av[1], O_RDONLY);
		printf("fd=%d\n", fd);
		if (!(check_n(fd)))
		{
			printf("err\n");
			return (0);
		}
		close (fd);
		fd = open (av[1], O_RDONLY);
	/* printf("figure=\n%s",*/ r = mega_fgr_val(fd);//);//validate(fd);
//	printf("r=\n%s", r->fgr_line);
	close(fd);
	}
	else
		printf("fillit tetro!\n");
//		printf("error\n");	
	return (0);
}
/*
int main(int ac, char **av)// huge main
{
	t_fgr *r;
//	int fd;
	if (ac == 2)
	{
		int	fd = open (av[1], O_RDONLY);
		printf("fd=%d-\n", fd);
		if (!(check_n(fd)))
			return();
		close(fd);
		fd = open(av[1], O_RDONLY);
		mega_fgr_val(fd);
		close(fd);
	}
	else
	{
		printf("argc");
	}
	
	/ *  printf("figure=\n%s",* / r = mega_fgr_val(fd);//);//validate(fd);
//	printf("r=\n%s", r->fgr_line);
	close(fd);
	return (0);
}
*/
/* int main (void)
{
	t_fgr *fgr;
	t_fgr *tmp;

	fgr = fgr_new('A', "0001");
	tmp = fgr_lst(fgr->fgr_chr, fgr->fgr_line, fgr);
	printf("%s\n", tmp->fgr_line);
	return (0);
}*/