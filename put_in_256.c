/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/06/25 21:32:37 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* int		rcrs(char **min_map, t_fgr *fgrlst)//recursion /
{
	return(99);
}*/

/* int		putin(char **map, t_fgr *fgr, int s)/ * puts 1 fgr in map * /
{
	int	i;
	int	j;
	int	k;
	int f;
	i = 0;
	j = -1;
//	s = 0;///
//	i = -1;
//	j = 0;
	printf("s=%d ", s);
	while (map[++j][i])
		while (map[j][i])
		{
			if (map[j][i] == '.')
			{
				k = -1;
				f = 0;
				while (++k < 16)
				{
					printf("m[j][j]=%c\nj=%d\ni=%d\n", map[j][i], j, i);
					printf("map[j+k/4=%s\n", map[j +  (k % s)]);
					printf("j=%d i=%d k=%d ", j , i, k);
					printf("j+k4=%d ", j + (k % s));
					printf("i+k/4=%d\n", i + (k / s));
					printf("[k4ik/4=%c\n", map[j + (k %s)][i + (k / s)]);//SEGA
					
				
				//	printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);
					if (((fgr->fgr_int >> k) & 1) == 1 && ((j + k % 4) < (s - 1)) && ((i + k / 4) < (s - 1)) && map[j + k % 4][i + k / 4] == '.')
						++f;
					if (f == 4)
					{
						k = -1;
						while (--f > 0 && ++k < 16)
						{
							map[j + k / 4][i + k % 4] = fgr->fgr_chr;
						}
						return (1);
					}
			//		printf(" fi=%d ", (fgr->fgr_int >> k) & 1);
				}
			}
			++i;
		}
	printf("\n");
	return (0);
}*/


			//		printf("i=%dj=%d", i , j);
				//	printf("", map[i][j]);
			//		f = 0;
					//printf(" fi=%d ", (fgr->fgr_int << k) & 1);


			/*		if ((fgr->fgr_int & (1 << k)) != 0)///////////
					if (map[j + k % s][i + k / s] == '.')
							++f;
					if (f == 4)
					{
						while (--f != 0)
							map[j + k % s][i + k / s] = fgr->fgr_chr;
						printf("map[j]=%s\n", map[j]);
						return (1);
					}*/
					
				/*	//map[j][i] = fgr->fgr_chr;
				//printf(" fi=%d ", (fgr->fgr_int << k) & 1);
		//			printf("m[j][j]=%c\nj=%d\ni=%d\n", map[j][i], j, i);
//////				printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
/*				printf("map[j+k/4=%s\n", map[j +  (k % s)]);
				printf("j=%d i=%d k=%d ", j , i, k);
				printf("j+k4=%d ", j + (k % s));
				printf("i+k/4=%d\n", i + (k / s));
				printf("[k4ik/4=%c\n", map[j + (k %s)][i + (k / s)]);//SEGA
//				printf("XXXXXYYYYYYYUUUUUUU m[null]=%s\n", map[NULL]);*/

int			putin(char **map, t_fgr *fgr, int s)
{
	int x;
	int y;
	int k;
	int f;//
	f = 0;
	y = -1;
	x = 0;
	printf("625!");
	while ((map[y] && map[++y][x]))
	{
		x = 0;
		while (map[y][x] )//&& map[y][x] == '.')
		{
			if (map[y][x] == '.')
			{
			if (((fgr->fgr_int >> k) & 1) == 1 && ((y + k % 4) < (s - 1)) && ((x + k / 4) < (s - 1)) && map[x + k % 4][x + k / 4] == '.')//
				++f;
			if (f == 4)
				if ((four_check(map, fgr, x, y, s)))
				{
					k = -1;
					printf("GGGGGGGG");
					while (++k < 16)
					{
					//	if (((fgr->fgr_int >> k) & 1) == 1 && ((y + k % 4) < (s - 1)) && ((x + k / 4) < (s - 1)) && map[x + k % 4][x + k / 4] == '.')//
					//		++f;
	//f=$4?
				//		if (((fgr->fgr_int & (1 << k))))
				//		{
							printf("y+k/4=%d x+4=%d k=%d\n", y + k / 4, x + k % 4, k);
							map[y + k / 4][x + k % 4] = ((char)fgr->fgr_chr);
					}
				}
		//???			return (1);
			}
		}
		++x;
	}
//	}
	return (0);
}

int			four_check(char **map, t_fgr *fgr, int x, int y, int s)
{
	int k;
	int f;

	k = 0;
	f = 0;
	while (k < 16 && (y + k / 4) < s && (x + k % 4) < s && map[y + k / 4][x + k % 4] == '.')
	{
		if (fgr->fgr_int & (1 << k))
			f++;
		++k;
	}
	if (f == 4)
		return (1);
	return (0);
}