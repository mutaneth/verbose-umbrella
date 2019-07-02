/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:32:18 by ddratini          #+#    #+#             */
/*   Updated: 2019/06/30 21:32:20 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			putin(char **map, t_fgr *fgr, int s)
{
	int x;
	int y;
	int f;
	int k;

	x = 0;
	y = -1;
//	k = -1;
	while (map[++y]/* [x]*/)
	{
		printf(" newln---");
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;
				f = 0;
				while (++k <= 15)
				{
			//		printf(" k_=%d ", ((fgr->fgr_int) & (1 << k)) == 1);
				//	printf(" k_=%d ", (fgr->fgr_int >> k) & 1);
				//	printf(" bit=%d ", (fgr->fgr_int >> k) & 1);
					if (fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k /4) < s)
							if ((x + k%4) < s)
							if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
					{
						++f;
					//	if (f == 4)
						//printf(" k_=%d ", (fgr->fgr_int >> k) & 1);//fgr->fgr_int & (1 << k));
					}
				}
				if (f == 4)
				{
					k = -1;
					while (++k <= 15)
					{	if (fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
						//	&& map[y + k/4][x + k%4] == '.')
							map[y + k/4][x+ k%4] = fgr->fgr_chr;
					}
					return (1);
				}
/*			//	if (map[y + k / 4][x + k % 4])
				while (++k < 16 && y + k / 4 < s && x + k % 4 < s)
				{
					if (fgr->fgr_int & (1 << ++k) && map[y + k / 4][x + k % 4])
						++f;
				}
				if (f > 3)
				{

				}
*/			}
		}
	}
	return (0);
}
