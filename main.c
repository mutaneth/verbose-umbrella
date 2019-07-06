/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/06 21:13:55 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
static void			ft_err()
{
	write(1, "error\n", 6);
}

static void			ft_use()
{
	write(1, "usage: ./fillit input_file\n", 27);//277
}

int 		read_max(int fd)
{
	int ret;
	char buf[546];//???? \0?

	if ((ret = read(fd, buf, 546)) == 546 || ret == -1)
	{
		ft_err();//error message
		return (0);
	}
	else
	{
		//ok actually write(1, "error msg\n", 10);//error message
//		close(fd);
		ft_err();
		return (1);
	}
}

int			st(char **av/*int fd */)//return fd if ok st
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	printf("fd=%d ", fd);
	if (read_max(fd) == 0)
	{
		printf(" readmax>26||-1 ");
		close(fd);	/*added: check max read bytes */
		return (0);//need free?? exit??
	}
	fd = open(av[1], O_RDONLY);
	if (!(check_n(fd)))
	{
		printf(" sl_n-wrong ");
		ft_err();
		close(fd);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	return (fd);
}

void		build_f(t_fgr *r, int fd)
{
	int c;
	int s;
	int i;
	char **map;

	c = fgr_count(r);
	s = sqrt(c * 4);//i guess s must be sqrt(all #'s * 4)// 2 figurs -> s = 5-6//c*4*4?
	printf(" m_c=%d ",c);
	printf(" m_s=%d ", s);
	map = mapc(r, s);
//	i=0;
	i = putin(map, r, s);
	if (i == 4)
	{
		printf("i=4");
//			place(map, r, s);
	}
	else
		printf(" iif!=4! ");
	i = -1;
	printf("\n");
	while (map[++i])
		printf("map[i]%s i=%d\n", map[i], i);
	close(fd);
}

int			main(int ac, char **av)// huge main
{
	t_fgr 	*r;
	int 	fd;

	if (ac == 2)
	{
		fd = st(av);
		if ((r = mega_fgr_val(fd)) == NULL)
		/*st();*/ //r = mega_fgr_val(st(av));//r = mega_fgr_val(fd);
		{
			ft_err();//close (fd); ? //fre??ext
			return (0);//+ errror message
		}
		else
		{
			printf("mgfgrvl-ok ");
			build_f(r, fd);
		}
	}
	else
		write(1, "./fillit tetro_file!\n", 21);//right use msg
		ft_use();
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
