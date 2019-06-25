/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/06/24 23:17:05 by hfalmer          ###   ########.fr       */
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
	while (map[++j][i])
	
		while (map[j][i])
		{
			if (map[j][i] == '.')
			{
				k = -1;
				f = 0;
				while (++k < 16)
				{
					if (((fgr->fgr_int >> k) & 1) == 1 && map[j][i] == ',' && (j + k % s) < s && (i + k / s) < s)
						++f;
					if (f == 4)
					{
						k = -1;
						while (--f > 0 && ++k < 16)
						{
							map[j + k / s][i + k % s] = fgr->fgr_chr;
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
}


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
//////////////				printf("k=%c\n", map[j + (k % 4)][i + (k / 4)]);*/
/*				printf("map[j+k/4=%s\n", map[j +  (k % s)]);
				printf("j=%d i=%d k=%d ", j , i, k);
				printf("j+k4=%d ", j + (k % s));
				printf("i+k/4=%d\n", i + (k / s));
				printf("[k4ik/4=%c\n", map[j + (k %s)][i + (k / s)]);//SEGA
//				printf("m[null]=%s\n", map[NULL]);*/
