/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/16 23:07:39 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 		read_max(int fd)
{
	int ret;
	char buf[546];//? \0?

	if ((ret = read(fd, buf, 546)) == 546 || ret == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	else
	{
//		close(fd);
		return (1);
	}
}

int			st(char **av/*int fd */)//return fd if ok st
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (read_max(fd) == 0)
	{
		close(fd);	/*added: check max read bytes */
		exit (0);//need free?? exit??
	}
	close(fd);//mb thats why
	fd = open(av[1], O_RDONLY);
	if (!(check_n(fd)))
	{
		ft_putendl("error");
		close(fd);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	return (fd);
}

void		build_f(t_fgr *r)
{
	int c;
	int i;
	char **map;
	t_fgr *fgrlist;//???
	int flg;

	fgrlist = r;
//	if (flg < 2)
		flg = 2;
	c = fgr_count(fgrlist);
	flg = sqrt(c * 4);//i guess s must be sqrt(all #'s * 4)// 2 figurs -> s = 5-6//c*4*4?
/*	printf(" m_c=%d ",c);
	printf(" m_s=%d ", s);*/	
	i = -1;
	map = mapc(flg);
//	if (putin(map, r, flg) == 4)//flg
//		place(map, r, 0,0);
//	if (putin(map, r, flg) == 202)
//		six(map, r, flg);
//	while (map[++i])
//		printf("\nmap[%d]%s|", i, map[i]);
	if (map)
	{	
	//	if 
		while (rcrs(&map, r) == 0)
		{
			map_free(map, flg);
			++flg;
	//		/* ft_cleanmem(map);*/ map_free(map, c);//free(map);
			map = mapc(flg);//tmp?
		}
	}
	print_map(map);
}

int			main(int ac, char **av)// huge main
{
	t_fgr	*r;
	int		fd;
	t_fgr	*tmp;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetro_file!");
		return (1);
	}
	if (!(fd = st(av)))
	{
		return(1);
	}
	if ((r = mega_fgr_val(fd)) == NULL)/*st();*/ //r = mega_fgr_val(st(av));//r = mega_fgr_val(fd);
	{
		ft_putendl("error");//close (fd); ? //fre??ext
		return (0);
	}
	else
	{
		tmp = r;
/*		while (tmp)
		{
			printf(" tmp->fgr_int=%d ", tmp->fgr_int);
			tmp = tmp->next;
		}//works lists
		return(111111);*/
		build_f(r);//here we build map, place figures, solving problems
		//if build_f () ok ?
		close(fd);//necssry?
	}
	return (0);
}

