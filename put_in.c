/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/06/24 21:52:07 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* int		rcrs(char **min_map, t_fgr *fgrlst)//recursion /
{
	return(99);
}*/
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

int		putin(char **map, t_fgr *fgr, int s)/* puts 1 fgr in map */
{
	int	i;
	int	j;
	int	k;
	int f;

	i = 0;
	j = -1;
//	i = -1;
//	j = 0;
	s = s + 0;
	write(1, "KKKKKKKKKK", 999);
	printf("SDASSDADQWQWQEEWRWER");
	while (map[++j][i])
	{
		i = 0;
		while (map[j][i])	//while (map[j][i] && map[j][i] == '.') //those are diff things we have to look for . evrywhere
		{
			if (map[j][i] == '.')
			{
				k = -1;
				f = 0;
				while (++k < 16)
				{
			//		f = 0;
					if (((fgr->fgr_int << k) & 1) == 1 && y + k /4 < s && x + k%4 < s
						&& map[y + k/4][x + k%4] == '.')//if ((fgr->fgr_int & (1 << k)) != 0)///////////
						++f;
///////////			map[j][i] = fgr->fgr_chr;
					printf(" fi=%d ", (fgr->fgr_int << k) & 1);
					if (map[j + k / 4][i + k % 4] == '.')//not s 4
							++f;
					if (f == 4)
					{
						k = -1;//new! fri 28.6
						while (--f != 0 && ++k < 16)//new
/*no check for k numb */	map[j + k / 4][i + k % 4] = fgr->fgr_chr;//map[j + k % s][i + k / s] = fgr->fgr_chr;
			//			printf("map[j]=%s\n", map[j]);
						return (4);//return(f);	
					//	return (1);
					}
				}
			}
			++i;
		}
	}
	printf("\n");
	return (0);
}//fills up to 2 cells