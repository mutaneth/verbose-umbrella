/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:42:11 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/10 19:24:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void print_map(char **map)
{
	int u;u = -1;
	while (map[++u])
		printf("\nmap[%d]%s|", u, map[u]);
}

int			place(char **map, t_fgr *fgr, int y, int x)// fgr/fgrlst?
{
	int k;
	int chi;
	int f;

	k = -1;
	f = 4;
	chi = fgr->fgr_int;
	if (chi == 281 * 2|| chi == 401 * 2||chi == 57 * 2|| chi == 27 * 2|| chi == 153 * 2)//|| chi == 29)
	{
		while (++k <= 12)
		{
			if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
			//	&& map[y + k/4][x + k%4] == '.')
			{
				if (map[y + k/4][x + (k % 4) -1])
				{map[y + k/4][x+ (k %4) - 1] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
				--f;
				}
			}
		}
		if (f == 0)
			return (2);
		else
			return (0);
	}
	if (chi == 29 )
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

int			rcrs(char **min_map, t_fgr *fgrlst)//recursion /
{
	int i;
	int x;
	int y;
	int t;
	static int p = -1;
//	if (putin() != 1)
	{
		printf("not placed%d", ++p);
	//	mapc();increase map
	}
	y = -1;
	x = -1;
//	min_map[0] = "AAA.";
//	min_map[0][0]='a'; 
//	min_map[0][1]='a';min_map[0][2]='a';//min_map[0][3]='a';
	while (min_map[++y])
	{
		t = 0;
	//	printf("\n mimap[y][t]=%c y=%d t=%d ", min_map[y][t + 1], y, t);
		printf("\n minmap[%d]=%s ", y, min_map[y]);
		while (min_map[y][t])//if ( t < flg_s)
		{
			i = -1;
			if (min_map[y][t] == '.')
			if (putin(min_map, fgrlst, y, t) == 4)//check putin in this coordinate!
			{
				place(min_map, fgrlst, y, t);//t for x
				printf(" -%s-", fgrlst->fgr_line);
				if (fgrlst->next)
					printf("\n , fgrlst->next\n");
				print_map(min_map);
		//		while (min_map[++i])
		//			printf("\nmap[%d]%s|", i, min_map[i]);
				if (fgrlst->next)
				{
					if (rcrs(min_map, fgrlst->next))
						return (1);
				}
		//		if (!(fgrlst->next))
		//			return (2);//break;
			//	else
			//	{
			//		return (2);
			//	}
				
			}
			++t;
		}
	}
//	if (!(fgrlst->next))
//		return (2);
	return (0);
	//six (map, r, s);
/*	if (r->fgr_int == 29)
	{
		int	res;
		int	fo;
		int	i;
		int	minx;
		char *str = r->fgr_line;
		res = 0;
		fo = -1;
		i = -1;
		minx = 3;
		while (++i < 16)
		{
			if (str[i] == '#')
			{
				if ((i % 4) < minx)
					minx = i % 4;
				if (fo == -1)
					fo = i;
				res += 1 << (i - fo + (fo % 4));
			}
		}
		res = res >> minx;
		r->fgr_int = res; printf(" res_int=%d ", r->fgr_int);
	}*/
		i = putin(min_map, fgrlst, y, x);
	if (i == 202)
		six (min_map, fgrlst, 0, 0);//map r s -changed??mod
	if (i == 4)
	{
		printf("i=4");
//			place(map, r, s);
	}
	else
		printf(" iif!=4! ");
	i = -1;
	printf("\n");
	while (min_map[++i])
		printf("map[%d]%s|\n", i, min_map[i]);
	return (0);
//	return(99);
}

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
int twenty_one(char **map, t_fgr *fgr, int y, int x)
{
	int f;
	int k;
	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
//	if (fgr->fgr_int == 29)//if x = 2 is filled??
//	{
		fgr->fgr_int  = (fgr->fgr_int << 2);// | 1; //if fgr is 2 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	if (map[y] && map[y][x])
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;
				f = 0;
				while (++k <= 12)
				{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if(map[y+ k /4 ][x + (k % 4) -2])//if (( y + k / 4) < s)
							//if ((x + ((k % 4) )-2) < s)//if ((x + k % 4 ) < s)
								if ( map[y + k/4][x + k%4  -2] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
			//		if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)/*(fgr->fgr_int & (1 << k)) * ((fgr->fgr_int >> k) & 1) */
			//			if (( y + k / 4) < s)
			//				if ((x + (k % 4) ) < s)//if ((x + k % 4 ) < s)
			///					if ( map[y + k/4 ][x + k%4 ] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
				//				{
				//					++f;
			//					}
				}//comment sec seg
				if (f == 4)//call nplace))
					return(4);//to: puton
		//			}//x-1 if 29 else   //well -1;+2 have put Z_up but lso unrelated fgrs..
			}
	return (0);
}
int			six(char **map, t_fgr *fgr, int y, int x)//correct placement for non corn fgrs
{
	int f;
	int k;
	int chi;
	int size;

	size = ft_strlen(map[0]);
	chi = fgr->fgr_int;
	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
	if (fgr->fgr_int == 29 || fgr->fgr_int == 29 * 2 * 2)//if x = 2 is filled??
		return (twenty_one(map, fgr, y , x));///
	else if (chi == 281 || chi == 401 || chi == 57 || chi == 27 || chi == 153)
	{
		fgr->fgr_int  = (fgr->fgr_int << 1);// | 1; //if fgr is 1 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	}
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
							if ( map[y + k /4])	//segs w/out it for some reason ;/
								if ((y + k / 4) < size && (x + k % 4 -1) < size)
								if ( map[y + k/4 ][x + k%4  -1] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
			//		if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
			//			if (( y + k / 4) < s)
			//				if ((x + (k % 4) ) < s)//if ((x + k % 4 ) < s)
			///					if ( map[y + k/4 ][x + k%4 ] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
				//				{
				//					++f;
			//					}
				}
				if (f == 4)
					return (4);
			}
	return (0);
}

int		putin(char **map, t_fgr *fgr, int y, int x)/* puts 1 fgr in map */
{
	int f;
	int k;
	int chi;
	int size;

	size = ft_strlen(map[0]);
//	printf(" pur_s=%d ", s);
	chi = fgr->fgr_int;
	if (chi == 281 || chi == 401 || chi == 57 || chi == 27 || chi == 153 || chi == 29 ||
		chi == 281*2 || chi == 401*2 || chi == 57*2 || chi == 27*2 || chi == 153*2 || chi == 29*2)
		return(six(map, fgr, y , x));//return (202);//six();
	y = -1;
	while (map[++y]/* [x]*/)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
				while (++k <= 12)
				{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (y + k / 4 < size)//if (( map[y + k / 4]) )//< s)
							if (x + k % 4 < size) //if ((map[y + k/4][x + (k % 4)] ) )//< s)//if ((x + k % 4 ) < s)
					//			if (x >= 2)
								if ( map[y + k/4][x + k%4] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
				}
				if (f == 4)
					return (4);
			}
		}
	}
	return (0);
}
