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
	s = sqrt(c * 4);
	printf(" C=%d ", c);
	printf("S=%d\n",s);
	flg = flg - 1 + 1;//
	if (s < 2)
		s = 2;
		s = 4;
	if (!(map = (char**)malloc(s * sizeof(char *)  + 1 )))
		return (NULL);
	while (++i < s)
	{
		if (!(map[i] = (char*)malloc(s * sizeof(char) + 1)))
			return (NULL);
		ft_memset(map[i], '.', s);
		map[i][s] = '\0';
	//	printf("%s\n", map[i]);
	}
	map[i] = 0;//!!!!!!!!!
	i = -1;
	i = -1;
//	while (map[++i])
//			printf("%s\n", map[i]);
//	while (++i < s)

	return (map);
}

/* void	map_free(char **map, t_fgr *fgrlst)// huita
{
	int i;

	i = -1;
	if (**map)
	{
		while (++i < (4 * fgr_count(fgrlst)))
			free(map[i]);
		free(*map);
		free(**map);
	}
} */

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
