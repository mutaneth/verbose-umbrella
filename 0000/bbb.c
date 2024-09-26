//fgr_int  = fgr_int | ( (fgrl[i] - '0') << (i - frst));
#include "../fillit/libft/libft.h"
#include <stdio.h>
int main(void)
{
	int n = 5;
	char *line= "0000000000000101";
	int i;
	int frst = -1;
	ft_print_bits(n);
	i = -1;
	n = 0;//!!!
	while (++i <= 15)
	{
		//n = n | ((line[i] - '0') << (i - 0));
		if (frst == -1 && line[i] - '0' == 1)
			frst = i;
		else
			n |= (line[i] - '0') << (i - frst);//(i - 0);
	}
	printf("\n");
	ft_print_bits(n);
	return (0);
}
