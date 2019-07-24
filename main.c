/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/24 19:48:08 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** st: return fd if ok st
*/

int		read_max(int fd)
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
		close(fd);
		return (1);
	}
}

int		st(char **av)
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
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	return (fd);
}

int		check_n(int fd)
{
	char	buf[22];
	int		ret;

	while ((ret = read(fd, buf, 21)) == 21)
	{
		buf[21] = '\0';
		if (buf[20] && buf[20] != '\n')
			return (0);
	}
	if (ret == 20)
		return (1);
	else
		return (0);
}

void	build_f(t_fgr *r)
{
	int		c;
	int		i;
	char	**map;
	t_fgr	*fgrlist;
	int		flg;

	fgrlist = r;
	flg = 2;
	c = fgr_count(fgrlist);
	flg = ft_sqrt(c * 4);
	i = -1;
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

int		main(int ac, char **av)
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
		return (1);
	if ((r = mega_fgr_val(fd)) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	else
	{
		tmp = r;
		build_f(r);
		free_fgr(r);
		close(fd);
	}
	return (0);
}
