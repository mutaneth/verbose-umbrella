/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/10 18:10:04 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
int 		read_max(int fd)
{
	int ret;
	char buf[546];//???? \0?

	if ((ret = read(fd, buf, 546)) == 546 || ret == -1)
	{
		ft_putendl("error");//error message
		return (0);
	}
	else
	{
		//ok actually write(1, "error msg\n", 10);//error message
//		close(fd);
		ft_putendl("error");
		return (1);
	}
}

int			st(char **av/*int fd */)//return fd if ok st
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	printf("1)fd_st=%d ", fd);
	if (read_max(fd) == 0)
	{
		printf(" readmax>26||-1 ");
		close(fd);	/*added: check max read bytes */
		return (0);//need free?? exit??
	}
	fd = open(av[1], O_RDONLY);
/*	if (!(check_n(fd)))
	{
		printf(" sl_n-wrong ");
		ft_putendl("error");
		close(fd);
		return (0);
	}*/
	fd = open(av[1], O_RDONLY);
	printf("3)op=%d",fd);
	return (fd);
}

void		build_f(t_fgr *r)
{
	int c;
//	int s;
//	int i;
	char **map;
//	t_fgr *fgr;
	t_fgr *fgrlist;//???
	int flg;

	fgrlist = r;
	//printf(" C=%d ", c);
	//printf("Ssqrt=%d\n",s);
//	if (flg < 2)
		flg = 2;
//		s = 4;
	//	s = 5;
	c = fgr_count(fgrlist);
	flg = sqrt(c * 4);//i guess s must be sqrt(all #'s * 4)// 2 figurs -> s = 5-6//c*4*4?
/*	printf(" m_c=%d ",c);
	printf(" m_s=%d ", s);
//	s = 5;
	map = mapc(fgrlst, s);
	i=0; */	
//	map = mapc(map, r);
	//flg = 0;
	int i = -1;
	flg = 4;
	map = mapc(flg);
	if (putin(map, r, flg) == 4)//flg
		place(map, r, 0,0);
//	if (putin(map, r, flg) == 202)
//		six(map, r, flg);
	while (map[++i])
		printf("\nmap[%d]%s|", i, map[i]);
//	while (rcrs(map, r, flg) == 0)
	{
//		++flg;
//		map = mapc(flg);//tmp?
	}
}

int			main(int ac, char **av)// huge main
{
	t_fgr 	*r;
	int 	fd;
	t_fgr	*tmp;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetro_file!");//right use msg
		return (1);
	}
	if (!(fd = st(av))) 
	{
		printf(" fdd=%d ", fd);
		return(1);
	}
	printf(" fdmain=%d ", fd);
	if ((r = mega_fgr_val(fd)) == NULL)/*st();*/ //r = mega_fgr_val(st(av));//r = mega_fgr_val(fd);
	{
		ft_putendl("error-inv");//close (fd); ? //fre??ext
		return (0);//+ errror message
	}
	else
	{
		printf("mgfgrvl-ok ");
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

/* int main (void)
{
	t_fgr *fgr;
	t_fgr *tmp;

	fgr = fgr_new('A', "0001");
	tmp = fgr_lst(fgr->fgr_chr, fgr->fgr_line, fgr);
	printf("%s\n", tmp->fgr_line);
	return (0);
}*/
