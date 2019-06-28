/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/06/28 16:38:50 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

	/*			printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
int 		read_max(int fd)
{
	int ret;
	char buf[546];

	if ((ret = read(fd, buf, 546)) == 546 || ret == -1)
		//error message
		return (0);
	else
	{
		//ok actually write(1, "error msg\n", 10);//error message
//		close(fd);
		return (1);
	}
}

int main(int ac, char **av)// huge main
{
	t_fgr *r;
	char **map;
	int i;
	int c;
	int s;

	if (ac == 2)
	{
		int	fd = open(av[1], O_RDONLY);
		printf("fd=%d ", fd);
		if (read_max(fd) == 0)
			return (0);
		close(fd);	/*added: check max read bytes */
		fd = open(av[1], O_RDONLY);
		if (!(check_n(fd)))
		{
			write(1, "error\n", 6);
			return (0);
		}
		close(fd);
		fd = open(av[1], O_RDONLY);
		r = mega_fgr_val(fd);
		if (r == NULL)
			return (0);//+ errror message
		printf("mgfgrvl-ok\n");
		c = fgr_count(r);
		s = sqrt(c * 4 * 4);//i guess s must be sqrt(all #'s * 4)// 2 figurs -> s = 5-6
		printf(" s=%d ", s);
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
	else
		write(1, "./fillit tetro_file!\n", 21);//right use msg
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
