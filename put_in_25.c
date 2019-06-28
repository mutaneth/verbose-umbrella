/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/06/25 19:08:53 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* int		rcrs(char **min_map, t_fgr *fgrlst)//recursion /
{
	return(99);
}*/

 int		putin(char **map, t_fgr *fgr, int s)/* puts 1 fgr in map */
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
		write(1, "KKKKKKKKKK", 999);
	printf("s=%d ", s);
	while (map[++j][i])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '.')
			{
				k = -1;
				f = 0;
				while (++k < 16)
				{
		/*			printf("m[j][j]=%c\nj=%d\ni=%d\n", map[j][i], j, i);
					printf("map[j+k/4=%s\n", map[j +  (k % 4)]);
					printf("j=%d i=%d k=%d ", j , i, k);
					printf("j+k4=%d ", j + (k % 4));
					printf("i+k/4=%d\n", i + (k / 4));
					printf("[k4ik/4=%c\n", map[j + (k % 4)][i + (k / 4)]);//SEGA
		*/			
				//	printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);
					if (((fgr->fgr_int >> k) & 1) == 1 && ((j + k % 4) < (s - 1)) && ((i + k / 4) < (s - 1)) && map[j + k % 4][i + k / 4] == '.')
						++f;
					if (f == 4)
					{
						k = -1;
						while (--f > 0 && ++k < 16)
							map[j + k / 4][i + k % 4] = fgr->fgr_chr;
						return (1);
					}
					printf(" fi=%d ", (fgr->fgr_int >> k) & 1);
				}
			}
			++i;
		}
	}
	printf("\n");
	return (0);
}//fills 3 cells
/*
int		four_check(char **map, t_fgr *fgr, int x, int y)
{
	if ()
}

			//		printf("i=%dj=%d", i , j);
				//	printf("", map[i][j]);
			//		f = 0;
					//printf(" fi=%d ", (fgr->fgr_int << k) & 1);


			/ *		if ((fgr->fgr_int & (1 << k)) != 0)///////////
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
//				printf("m[null]=%s\n", map[NULL]); */

/*
 int putin(char **map, t_fgr *fgr, int s)
{
	int x;
	int y;
	int k;

	x = -1;
	y = 0;
	if (f == 4)
	{
		k = -1;
		while (--f > 0 && ++k < 16)
		{
			map[j + k / 4][i + k % 4] = fgr->fgr_chr;
		}
		return (1);
	}

	while ((map[y][++x]))
	{
		while (map[y][x] && map[y][x] == '.')
		{	
			if ((four_check(map, fgr, x, y)))
			{
				k = -1;
				while (++k < 16)
				{
					if (((fgr->fgr_int >> k) & 1))
						map[y + k / 4][x + k % 4] = (char)fgr->fgr_chr);
				}
			}
			y++;
		}
	}
}*/