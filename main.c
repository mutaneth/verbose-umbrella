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

int			read_max(int fd)
{
	int		ret;
	char	buf[546];

	if ((ret = read(fd, buf, 546)) == 546 || ret == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	else
	{
		return (1);
	}
}

int			check_n(int fd)
{
	char	buf[22];
	int		ret;

	while ((ret = read(fd, buf, 21)) == 21)
	{
		buf[21] = '\0';
		if (buf[20] && buf[20] != '\n')
			return (0);/* no \n */
	}
	if (ret == 20)
		return (1);
	else
		return (0);/* bad fgr */
}

int			st(char **av/*int fd */)//return fd if ok st
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (read_max(fd) == 0)
	{
		close(fd);
		exit(0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!(check_n(fd)))
	{
		ft_putendl("error");
		close(fd);
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	return (fd);
}

void		build_f(t_fgr *r)
{
	int		c;
	char	**map;
	t_fgr	*fgrlist;
	int		flg;

	fgrlist = r;
	c = fgr_count(fgrlist);
	flg = sqrt(c * 4);
	map = mapc(flg);
	if (map)
	{
		while (rcrs(&map, r) == 0)
		{
			map_free(map, flg);
			++flg;
			map = mapc(flg);
		}
	}
	print_map(map);
	map_free(map, flg);
}

int			main(int ac, char **av)
{
	t_fgr	*r;
	int		fd;
	t_fgr	*tmp;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetro_file!");
		return (1);
	}
	if ((fd = st(av)) < 3)
		return (1);
	if ((r = mega_fgr_val(fd)) == NULL)
	{
		free_fgr(&r);
		ft_putendl("error");
		return (0);
	}
	else
	{
		tmp = r;
		build_f(r);
		free_fgr(&r);
		close(fd);
	}
	return (0);
}
