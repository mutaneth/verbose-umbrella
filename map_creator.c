/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:52:31 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/16 23:52:35 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int			ft_sqrt(double dcf)
{
	int i;

	i = 0;
	while (i * i < dcf)
	{
		++i;
	}
	return ();
}*/

int		fgr_count(t_fgr *fgrlst)
{
	int		c;
	t_fgr	*tmpl;

	if (!fgrlst)//?
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

char	**mapc(int flg)//, int c_fg)/* creates the minimal start map*/
{
	char	**map;
	int		i;

	i = -1;//free?
	if (!(map = (char**)malloc((flg + 1) * sizeof(char *))))
		return (NULL);//free
	while (++i < flg)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (flg + 1))))
			return (NULL);//free
		ft_memset(map[i], '.', flg);
		map[i][flg] = '\0';
	}
	map[i] = 0;
	i = -1;
	return (map);
}

 void	map_free(char **map, int fgc)//t_fgr *fgrlst)
{
	int i;

	i = -1;
	if (map)
	{
		while (++i < fgc )
			free(map[i]);
	//	free(*map);
		free(map);
	}
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
*/
