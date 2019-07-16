/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 03:40:51 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/14 15:53:50 by ddratini         ###   ########.fr       */
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

int		fgr_count(t_fgr *fgrlst)/* just count fgrs*/
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
	//	printf("%s\n", map[i]);
	}
	map[i] = 0;
	i = -1;
//	while (map[++i]) //			printf("%s\n", map[i]); //	while (++i < s)
	return (map);
}

 void	map_free(char **map, int fgc)//t_fgr *fgrlst)// huita
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

char	**map_creator(t_fgr *fgrlst) variant s kuchei malloc
{
	char	**map;


}
*/
