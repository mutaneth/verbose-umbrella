/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 03:40:51 by hfalmer           #+#    #+#             */
/*   Updated: 2019/05/23 04:15:49 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fgr_count(t_fgr *fgrlst)/* just count fgrs*/
{
	int		c;
	t_fgr	*tmpl;

	if (!fgrlst)
		return (0);
	c = 1;
	tmpl = fgrlst;
	while (tmpl->next)
	{
		c++;
		tmpl = tmpl->next;
	}
	return (c);
}

char	**mapc(t_fgr *fgrlst, int flg)/* creates the minimal start map*/
{
	int		c;
	int		s;
	char	**map;
	int		i;

	i = -1;
	c = fgr_count(fgrlst);
	s = sqrt(c * 4) + flg;// 0 or 1
	if (s < 4)
		s = 4;
	if (!(*map = (char**)malloc(s * sizeof(char))))
		return (NULL);
	while (++i < s)
	{
		if (!(map = (char*)malloc(s * sizeof(char))))
			return (NULL);
		ft_memset(map[i], '.', s);
	}
	return (map);
}

void	map_free(char **map, t_fgr *fgrlst)// huita
{
	int i;

	i = -1;
	if (**map)
	{
		while (++i < (4 * fgr_count(fgrlst)))// ??
			free(map[i]);
		free(*map);
		free(**map);
	}
}

char		**map_increaser(t_fgr *fgrlst, char **map, int flg)// flg = iterrator
{
	char	**big_map;

	map_free(map, fgrlst);
	big_map = mapc(fgrlst, flg);
	return (big_map);
}


/* char	**mapc(int s)
{
	char	**map[s][s];
	int		i;
	int		j;

	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			map[i][j] = '.';
	}
	return (map);
}

char	**map_creator(t_fgr *fgrlst)/* variant s kuchei malloc
{
	char	**map;


}
*/
