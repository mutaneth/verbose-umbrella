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
	/* printf("figure=\n%s",*/ r = mega_fgr_val(fd);//);//validate(fd);
//	printf("r=\n%s", r->fgr_line);
	close(fd);
	return (0);
}
