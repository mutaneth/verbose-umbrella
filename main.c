#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"
#include <math.h>//
	/*			printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
int main(int ac, char **av)// huge main
{
	t_fgr *r;
	char **map;
	int i;
	int c;
	int s;
	if (ac == 2)
	{
		int	fd = open (av[1], O_RDONLY);
		printf("fd=%d ", fd);
		if (!(check_n(fd)))
		{
			write(1, "err\n", 4);
			return (0);
		}
		close (fd);
		fd = open (av[1], O_RDONLY);
		r = mega_fgr_val(fd);
		printf("ok\n");
		map = mapc(r);
		i = -1;
	//	while (map[++i])
	//		printf("%s\n", map[i]);
		c = fgr_count(r);
		s = sqrt(c * 4);
		i = putin(map, r, s);
		i = -1;
		while (map[++i])
			printf("map[i]%s i=%d\n", map[i], i);
		close(fd);
	}
	else
		write(1, "fillit tetro!\n", 14);
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