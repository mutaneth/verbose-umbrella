/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:32:18 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/06 21:13:13 by ddratini         ###   ########.fr       */
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
	y = -1; k = 0;k=2;
	printf("knumofbit=%d ik_=%d ", k,(fgr->fgr_int >> 2) & 1u);//this shows 1 or no in the >>place
	printf("bitsval=%d ", (fgr->fgr_int & (1u << 2)));//and this one - the value externally
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
				while (++k <= 12)
				{
			//		printf(" k_=%d ", ((fgr->fgr_int) & (1 << k)) == 1);
	//				printf(" ik_=%d ", (fgr->fgr_int >> k) & 1u);
	//				printf(" ik_=%d ", fgr->fgr_int & (1u << k));
				//	printf(" bit=%d ", (fgr->fgr_int >> k) & 1);
				//	ft_print_bits(fgr->fgr_int);
	//	 printf("\n -"); //ft_print_bits(fgr->fgr_int >>8); printf("-");
		//			if (k < 8) ft_print_bits(fgr->fgr_int);
		//			else if (k < 16)
		//				ft_print_bits((fgr->fgr_int >> 8));// (k - 7));
		//			else if (k == 16)
		//				printf("?        ");
					
				//	ft_print_bits();
					if (fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k /4) < s)
							if ((x + k%4) < s)
								if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
							//	if (f == 4)
								}
			//		ft_print_bits((fgr->fgr_int & (1 << k)));
//					ft_print_bits((fgr->fgr_int >> k) & 1);//this was important 
//					printf("\n   ");
				//printf(" k_=%d ", (fgr->fgr_int >> k) & 1);//fgr->fgr_int & (1 << k));}	
				}
				if (f == 4)
				{
					k = -1;
					while (++k <= 12)
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
