/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/10 19:24:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			rcrs(char **min_map, t_fgr *fgrlst)//recursion /
{
//	if (putin() != 1)
	{
		printf("not placed");
	//	mapc();increase map
	}
	return(99);
}

/*void 		alg()
{

}*/
/*int 		place(char **map, t_fgr *fgr, int s)
{
//	if (f == 4)
		int	i;
	int	j;
	int	k;
	int f;

	i = 0;
	j = -1;
//	i = -1;
//	j = 0;
	s += s -1;
	while (map[++j][i])
	{
		i = 0;
		while (map[j][i] && map[j][i] == '.')
		{
			k = -1;
			f = 0;
			while (++k < 16)
			{
				if (((fgr->fgr_int << k) & 1) == 1 && map[j + k % 4][i + k / 4])//if ((fgr->fgr_int & (1 << k)) != 0) 
//					map[j][i] = fgr->fgr_chr;
				if (map[j + k % 4][i + k / 4] == '.')
	//				++f;
			//	while (--f != 0)
						map[j + k % 4][i + k / 4] = fgr->fgr_chr;
	//				return(1);////
			}
			++i;
		}
	}
	printf("\n");
	return (0);
}
*/
int six(char **map, t_fgr *fgr, int s)//correct placement for non corn fgrs
{
	int x;
	int y;
	int f;
	int k;
	int d;
	printf( " fgr-fin=%d ", fgr->fgr_int);
	if (fgr->fgr_int == 29)
		fgr->fgr_int  = (fgr->fgr_int << 2) | 1; //if fgr is 2 points + x = start
	else
		fgr->fgr_int  = (fgr->fgr_int << 1) | 1; //if fgr is 1 points + x = start
	ft_print_bits(fgr->fgr_int);
	y = -1; 	x = 0;/*??*/ k = 0;k=2;
	y = 0;
	//fgr->fgr_int = rev_bit(fgr->fgr_int);
	while (map[y]/* [x]*/)
	{
		printf(" newln---");
		/*x = 2;*/x = 0;//x = -1;
		while (map[y][x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
				d = 2 - 1;
				while (++k <= 12)
				{
					if (k>0)
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k / 4) < s)
							if ((x + (k % 4) ) < s)//if ((x + k % 4 ) < s)
								if ( map[y + k/4][x + k%4] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
				}
				if (f == 4)
				{
					k = -1;
					d = 2 - 1;
					while (++k <= 12)
					{	if (k>0)
						if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
						//	&& map[y + k/4][x + k%4] == '.')
							map[y + k/4][x+ (k %4)] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
					}
					return (1);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}

int		putin(char **map, t_fgr *fgr, int s)/* puts 1 fgr in map */
{
	int x;
	int y;
	int f;
	int k;
	int d;

	printf(" pur_s=%d ", s);
//	fgr->fgr_int  = (fgr->fgr_int << 2) | 1;
	ft_print_bits(fgr->fgr_int);
	if (fgr->fgr_int == 281 || fgr->fgr_int == 401 || fgr->fgr_int == 57 || fgr->fgr_int == 27 || fgr->fgr_int == 153 || fgr->fgr_int == 29)
		six();
	y = -1; 	x = 0;/*??*/ k = 0;k=2;
	printf("knumofbit=%d ik_=%d ", k,(fgr->fgr_int >> 2) & 1u);//this shows 1 or no in the >>place
	printf("bitsval=%d ", (fgr->fgr_int & (1u << 2)));//and this one - the value externally
	y = 0;
	//fgr->fgr_int = rev_bit(fgr->fgr_int);
	while (map[y]/* [x]*/)
	{
		printf(" newln---");
		/*x = 2;*/x = 0;//x = -1;
		while (map[y][x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
				d = 2 - 1;
				while (++k <= 12)
				{
	//				printf(" fint>>k) & 1=%d k=%d ", (fgr->fgr_int >> k) & 1, k);
	//				printf(" x+k=%d y+k/4=%d\n", x + k % 4, y+ k /4);
					if (k>0)
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k / 4) < s)
							if ((x + (k % 4) ) < s)//if ((x + k % 4 ) < s)
					//			if (x >= 2)
								if ( map[y + k/4][x + k%4] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
							//	if (f == 4)
								}
				}
				if (f == 4)
				{
					k = -1;
					d = 2 - 1;
					while (++k <= 12)
					{	if (k>0)
						if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
						//	&& map[y + k/4][x + k%4] == '.')
							map[y + k/4][x+ (k %4)] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
					}
					return (1);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}
