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

int			place(char **map, t_fgr *fgr, int y, int x)// fgr/fgrlst?
{
	int k;

	k = -1;
	while (++k <= 12)
	{
		if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
		//	&& map[y + k/4][x + k%4] == '.')
			map[y + k/4][x+ (k %4)] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
	}
	return (1);
}

int			rcrs(char **min_map, t_fgr *fgrlst, int flg_s)//recursion /
{
	int t;
	int i;
	int x;
	int y;
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
		t = -1;
	//	printf("\n mimap[y][t]=%c y=%d t=%d ", min_map[y][t + 1], y, t);
		printf("\n minmap[%d]=%s ", y, min_map[y]);
		while (min_map[y][++t])//if ( t < flg_s)
		{
			i = -1;
			if (min_map[y][t] == '.')
			if (putin(min_map, fgrlst, flg_s, y, t) == 4)//check putin in this coordinate!
			{
				place(min_map, fgrlst, y, t);//t for x
				printf(" -%s-", fgrlst->fgr_line);
				if (fgrlst->next)
					printf("\n , fgrlst->next\n");
				while (min_map[++i])
					printf("\nmap[%d]%s|", i, min_map[i]);
				if (fgrlst->next)
				{
					if (rcrs(min_map, fgrlst->next, flg_s))
						return (1);
				}
				if (!(fgrlst->next))
					return (2);//break;
			//	else
			//	{
			//		return (2);
			//	}
				
			}
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
		i = putin(min_map, fgrlst, flg_s, y, x);
	if (i == 202)
		six (min_map, fgrlst, flg_s, 0, 0);//map r s -changed??mod
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
int twenty_one(char **map, t_fgr *fgr, int s, int y, int x)
{
	int f;
	int k;
	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
	if (fgr->fgr_int == 29)//if x = 2 is filled??
	{
		fgr->fgr_int  = (fgr->fgr_int << 2);// | 1; //if fgr is 2 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	}
	else
	{
		fgr->fgr_int  = (fgr->fgr_int << 1);// | 1; //if fgr is 1 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	}
	while (map[y]/* [x]*/)
	{
		/*x = 2;*/x = 0;//x = -1;
		while (map[y][x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;
				f = 0;
				while (++k <= 12)
				{
					if (k == 0) //for 29
					{
						if ((fgr->fgr_int >> k) & 1)
							if (( y + k / 4) < s) //+ x+2
							if ( map[y + k/4 + 0][x + (k/* +2*/)%4  -2] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
					}
					else
					{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k / 4) < s)
							if ((x + ((k % 4) )-2) < s)//if ((x + k % 4 ) < s)
								if ( map[y + k/4 + 0][x + k%4  -2] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
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
				{
					k = -1;
					while (++k <= 12)
					{	////////////if (k>0)
						if ((fgr->fgr_int >> k) & 1 && k == 0)
						{
							map[y + k/4  ][x+ ((k/*+2*/) %4) -2] = fgr->fgr_chr;//x+2 for 29
						}
						else
						{
						if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
							/* if*/// 	&& map[y + k/4][x + k%4] == '.')
/*why norm fgs place??*/	map[y + k/4  ][x+ (k %4) -2] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
						}
					}//x-1 if 29 else   //well -1;+2 have put Z_up but lso unrelated fgrs..
					return (1);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}
int			six(char **map, t_fgr *fgr, int s, int y, int x)//correct placement for non corn fgrs
{
	int f;
	int k;
	printf( " fgr-fin=%d ", fgr->fgr_int);//maybe not 1/ 2??????
	if (fgr->fgr_int == 29)//if x = 2 is filled??
	{
		return (twenty_one(map, fgr, s, 0 ,0));///
	//	fgr->fgr_int  = (fgr->fgr_int << 2);// | 1; //if fgr is 2 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	}
	else
	{
		fgr->fgr_int  = (fgr->fgr_int << 1);// | 1; //if fgr is 1 points + x = start
		printf(" mvdint=%d ", fgr->fgr_int);
	}
	while (map[y]/* [x]*/)
	{
		/*x = 2;*/x = 0;//x = -1;
		while (map[y][x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
	/*			if (x < 2)
				{
					if (fgr->fgr_int == 29)//if x = 2 is filled??
						fgr->fgr_int  = (fgr->fgr_int << 2) | 1; //if fgr is 2 points + x = start
					else
						fgr->fgr_int  = (fgr->fgr_int << 1) | 1; //if fgr is 1 points + x = start
				}
	*/			while (++k <= 12)
				{
			//		if (x >= 2 &&  k>0)//?????? s+=-1;0?
		//			if (x < 2)// int == 29
		//			{
				//	if (x == 3)
					if (k == 0) //for 29
					{
						if ((fgr->fgr_int >> k) & 1)
							if (( y + k / 4) < s) //+ x+2
							if ( map[y + k/4 + 0][x + (k/* +2*/)%4  -1] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
					}
					else
					{
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k / 4) < s)
							if ((x + ((k % 4) )-1) < s)//if ((x + k % 4 ) < s)
								if ( map[y + k/4 + 0][x + k%4  -1] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
								}
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
				{
					k = -1;
					while (++k <= 12)
					{	////////////if (k>0)
						if ((fgr->fgr_int >> k) & 1 && k == 0)
						{
							map[y + k/4  ][x+ ((k/*+2*/) %4) -1] = fgr->fgr_chr;//x+2 for 29
						}
						else
						{
						if ((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))//if (((fgr->fgr_int << k) & 1))//&& y + k /4 < s && x + k%4 < s
							/* if*/// 	&& map[y + k/4][x + k%4] == '.')
/*why norm fgs place??*/	map[y + k/4  ][x+ (k %4) -1] = fgr->fgr_chr;//map[y + k/4][x+ k%4] = fgr->fgr_chr;
						}
					}//x-1 if 29 else   //well -1;+2 have put Z_up but lso unrelated fgrs..
					return (1);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}

int		putin(char **map, t_fgr *fgr, int s, int y, int x)/* puts 1 fgr in map */
{
	int f;
	int k;

//	printf(" pur_s=%d ", s);
	if (fgr->fgr_int == 281 || fgr->fgr_int == 401 || fgr->fgr_int == 57 || fgr->fgr_int == 27 || fgr->fgr_int == 153 || fgr->fgr_int == 29)
		return(six(map, fgr, s, 0 ,0));//return (202);//six();
	while (map[y]/* [x]*/)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '.')//when found space check in cucle fitting of the fgr
			{
				k = -1;//k  =2;
				f = 0;
				while (++k <= 12)
				{
	//				printf(" fint>>k) & 1=%d k=%d ", (fgr->fgr_int >> k) & 1, k);
	//				printf(" x+k=%d y+k/4=%d\n", x + k % 4, y+ k /4);
					if ((fgr->fgr_int >> k) & 1)//((fgr->fgr_int >> k) & 1)//(fgr->fgr_int & (1 << k))/* ((fgr->fgr_int >> k) & 1)*/
						if (( y + k / 4) < s)
							if ((x + (k % 4) ) < s)//if ((x + k % 4 ) < s)
					//			if (x >= 2)
								if ( map[y + k/4][x + k%4] == '.')//if ( map[y + k/4][x + k%4] == '.')//check evry inti,map's boundaries/'.' in that place
								{
									++f;
							//	if (f == 4)
								}
				}
				if (f == 4)
				{
					return (4);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}
