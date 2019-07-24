/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:26:47 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/06 20:05:24 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     putin(char **map, t_fgr *fgr, int s)
{
    int x;
    int y;
    int f;
    int k;

    s = 4;
    y = 0;
    k = -1;
    while (++k < 16)
        printf("%d,", ((fgr->fgr_int & (1 << k)) == 1 ? (fgr->fgr_int>>k) & 1 : 0));
    printf("\n");
    while (map[y])
    {
        x = 0;
        while(map[x][y])
        {
            if (map[x][y] && map[x][y] == '.')
            {
                k = -1;
                f = 0;
                while (++k < 13)
                {
      //              printf("kb = %d\n", (fgr->fgr_int & (1 << k) ? 1 : 0));
                    if ((x + (k / 4) < s && (y + (k % 4)) < s && (fgr->fgr_int & (1 << k))))
                    {
                        if (map[x + (k % 4)][y + (k / 4)] == '.')
                        f++;
                        if (f == 4)
                        {
                            k = -1;
                            while (++k < 13 && f > 0)
                            {
                                if ((y + (k / 4) < s && (x + (k % 4)) < s && (fgr->fgr_int & (1 << k))) && map[x + (k % 4)][y + (k / 4)] == '.')
                                {
                                    map[x + (k / 4)][y + (k % 4)] = fgr->fgr_chr;
                                    f--;
                                    printf("f = %d\n", f);
//                                    printf("kb = %d\n", (fgr->fgr_int & (1 << k) ? 1 : 0));
                                }
                                    if (f == 0)
                                        return(1);
                            }
                        }
                    }
                }
            }
            x++;
        }
        y++;
    }
    return (0);
}
