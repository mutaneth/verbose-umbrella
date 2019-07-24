/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/24 19:38:09 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char **map)
{
	int u;
	u = -1;
	while (map[++u])
		printf("%s\n", map[u]);
}

void		dot(char **map, t_fgr *fi)
{
	int y;
	int x;
	char bu;

	bu = fi->fgr_chr;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == bu)
				map[y][x] = '.';
		}
	}
}

int			place(char **map, t_fgr *fgr, int y, int x)// fgr/fgrlst?
{
	int k;
	int chi;
	int f;

	k = -1;
	f = 4;
	chi = fgr->fgr_int;
	if (chi == 281 * 2|| chi == 401 * 2||chi == 57 * 2|| chi == 27 * 2|| chi == 153 * 2)
	{
		while (++k <= 12)
		{
			if ((fgr->fgr_int >> k) & 1)
			{
				if (map[y + k/4][x + (k % 4) -1])
				{
					map[y + k/4][x+ (k %4) - 1] = fgr->fgr_chr;
					--f;
				}
			}
		}
		if (f == 0)
			return (2);
		else
			return (0);
	}
	if (chi == 29 || chi == 29 * 4)
	{
		while (++k <= 12)
		{
			if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
			//	&& map[y + k/4][x + k%4] == '.')
			{
				map[y + k/4][x+ (k %4) -2] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
				--f;
			}
		}
		if (f == 0)
			return (29);
		else
			return (0);
	}
	while (++k <= 12)
	{
		if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
		//	&& map[y + k/4][x + k%4] == '.')
		map[y + k/4][x+ (k %4)] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
	}//mb nof f
	if (f == 0)
		return (1);
	else
		return (0);	
}

int			rcrs(char ***minmap, t_fgr *fgrlst)//recursion /
{
	int i;
	int y;
	int xt;
	int chpl;
	char **min_map;

	min_map = *minmap;
	y = -1;
	while (min_map[++y])
	{
		xt = -1;
		while (min_map[y][++xt])//if ( t < flg_s)
		{
			i = -1;
			chpl = 0;
			if (min_map[y][xt] == '.')
				if (putin(min_map, fgrlst, y, xt) == 4)//check putin in this coordinate!
				{
					chpl = place(min_map, fgrlst, y, xt);//t for x
					if (fgrlst->next)
					{
						if (rcrs(&min_map, fgrlst->next))
							return (1);
						dot(min_map, fgrlst);
					}
					if (!(fgrlst->next))
						return (2);
				}
		}
	}
	return (0);
}

int			twenty_one(char **map, t_fgr *fgr, int y, int x)
{
	int f;
	int k;
	int size;

	if (!fgr)
		return(0);
//	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
	if (fgr->fgr_int == 29)//if x = 2 is filled??
	{
		fgr->fgr_int  = (fgr->fgr_int << 2);// | 1; //if fgr is 2 points + x = start
//		printf(" mvdint=%d ", fgr->fgr_int);
	}
	size = ft_strlen(map[0]);
	if (map[y] && map[y][x])
		if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
		{
			k = -1;
			f = 0;
			while (++k <= 12)
			{
				if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
					if(y+k/4 < size)//if(map[y+ k /4 ][x + (k % 4) -2])//if (( y + k / 4) < s)
						if((x + (k % 4) -2) >= 0 && (x + (k % 4) -2) < size)
						//if ((x + ((k % 4) )-2) < s)//if ((x + k % 4 ) < s)
							if ( map[y + k/4][x + k%4  -2] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
							{
								++f;
							}
			}
			if (f == 4)
				return(4);//to: puton //			}//x-1 if 29 else   //well -1;+2 have put Z_up but lso unrelated fgrs..
		}
	return (0);
}
int			six(char **map, t_fgr *fgr, int y, int x)//correct placement for non corn fgrs
{
	int f;
	int k;
	int chi;
	int size;

	if (!fgr)
		return (0);
	chi = fgr->fgr_int;
//	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
	if (fgr->fgr_int == 29 || fgr->fgr_int == 29 * 2 * 2)//if x = 2 is filled??
		return (twenty_one(map, fgr, y , x));///
	else if (chi == 281 || chi == 401 || chi == 57 || chi == 27 || chi == 153)
	{
		fgr->fgr_int  = (fgr->fgr_int << 1);// | 1; //if fgr is 1 points + x = start
	//	printf(" mvdint=%d ", fgr->fgr_int);
	}
	size = ft_strlen(map[0]);
	if (map[y] && map[y][x])//mb rcrs?
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
				while (++k <= 12)
				{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if ((x + (k % 4) - 1) >= 0) //if (( y + k / 4) < s)
						//	if ((x + ((k % 4) )-1) < s)//if ((x + k % 4 ) < s)
							if (y + k /4 < size)	//segs w/out it for some reason ;/
								if ((y + k / 4) < size && (x + k % 4 -1) < size)
									if ( map[y + k/4 ][x + k%4  -1] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
									{
										++f;
									}
				}
				if (f == 4)
					return (4);
			}
	return (0);
}

int			putin(char **map, t_fgr *fgr, int y, int x)/* puts 1 fgr in map */
{
	int f;
	int k;
	int chi;
	int size;

//	printf(" pur_s=%d ", s);
	chi = fgr->fgr_int;
	if (chi == 281 || chi == 401 || chi == 57 || chi == 27 || chi == 153 || chi == 29 ||
		chi == 281*2 || chi == 401*2 || chi == 57*2 || chi == 27*2 || chi == 153*2 || chi == 29*2*2)
		return(six(map, fgr, y , x));//return (202);//six();
	size = ft_strlen(map[0]);
		if (map[y] && map[y][x])
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;
				f = 0;
				while (++k <= 12)
				{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (y + k / 4 < size)//if (( map[y + k / 4]) )//< s)
							if (x + k % 4 < size) //if ((map[y + k/4][x + (k % 4)] ) )//< s)//if ((x + k % 4 ) < s)
					//			if (x >= 2)
								if ( map[y + k/4][x + k%4] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;//expresion has occured????????mb stack
								}
				}
				if (f == 4)
					return (4);
			}
	return (0);
}
