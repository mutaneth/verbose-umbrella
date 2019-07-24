#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
 #include <unistd.h>
int main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	printf("fdo=%d ", fd);
	close(fd);
	printf("\nfdc=%d ", fd);
	exit(0);
}
