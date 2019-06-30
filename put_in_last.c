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
	k = -1;
	while (map[++y][x])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '.')
			{
			//	k = -1;
				f = 0;
				if (fgr->fgr_int & (1 << ++k))
			//	if (map[y + k / 4][x + k % 4])
			//		while (++k < 16 && y + k / 4 < s && x + k % 4 < s)
				{
			}
		}
	}
	return (0);
}
