/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/06 21:02:05 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_int(char const *str)/* get int ))*/
{
    int	res;
    int	fo;
    int	i;
    int	minx;

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
    return (res);
}

char			*ft_fgr_line(int fd)// malloc??
{
    int i;
    char *tmp;
    char *fgrl;

    i = -1;
    fgrl = "";
    while(++i < 4  && get_next_line(fd, &tmp) == 1)
    {
        if (!tmp)
        {
            printf("kek");
            return (NULL);
        }
        if (ft_strlen(tmp) == 4)
            fgrl = ft_strrejoin(fgrl, tmp, 1);//ft_strrejoin(tmp, fgrl, -1);
        else
        {
            if (tmp)
                free(tmp);
            if (fgrl) free(fgrl); //////////
            return (NULL);//free fgrl?
        }
    }
    if (i != 4 && get_next_line(fd, &tmp) != 1)
        return (NULL);
    printf("fgrl=%s", fgrl);
    return (fgrl);
}

t_fgr			*fgr_new(char fgr_chr, char *line)/* creates new node in t_fgr. chr starts with 65 and then iterates to 90*/
{
    t_fgr	*fgr;

    if (!(fgr = (t_fgr*)malloc(sizeof(t_fgr))))
        return (NULL);
    fgr->fgr_int = -1;
    fgr->fgr_chr = fgr_chr;
    fgr->fgr_line = ft_strdup(line);//do we need to check?
    fgr->next = NULL;
    return (fgr);
}

void	fgr_push_back(t_fgr **begin_list, char *data, char i)
{
    t_fgr	*tmp;

    if (!(*begin_list))
    {
        *begin_list = fgr_new(i, data);
        return ;
    }
    tmp = *begin_list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = fgr_new(i, data);
}

int			int_check(t_fgr *fgr)
{
    t_fgr	*tmp;
    int		fg;

    tmp = fgr;
    while (tmp)// 1 elem?
    {
        fg = tmp->fgr_int;
        if ((fg != 15 || fg != 116 || fg != 114 || fg != 51
             || fg != 54 || fg != 71 || fg != 99 || fg != 113
             || fg != 39 || fg != 23 || fg != 785 || fg != 305
             || fg != 306 || fg != 802 || fg != 561 || fg != 562
             || fg != 547 || fg != 275 || fg != 4369))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

t_fgr		*after_line(int fd)/* just check \n and \0 yuhoo and fill the fgr*/
{
    char	*line;
    int		i;
    char	buf[2];//buf[] = "-";//buf[2];
    int		check;
    t_fgr	*fgr;

    fgr = NULL;
    i = 'A' - 1;
    while ((line = ft_fgr_line(fd)) && ++i < 'Z')
    {
        if (((check = read(fd, buf, 1)) == 1) && buf[0] != '\n')
            return (NULL);// free
        if (!check)
        {
            fgr_push_back(&fgr, line, (char)i);
            break;
        }
        printf("i=%c\n", (char)i);
        fgr_push_back(&fgr, line, (char)i);
    }
    return (fgr);
}

t_fgr			*mega_fgr_val(int fd)
{
    t_fgr *ok_fgr;
    t_fgr *tmp;

    ok_fgr = NULL;
    if (!(ok_fgr = after_line(fd)))
    {
        printf("bad");
        return (NULL);
    }
    tmp = ok_fgr;
    while (tmp)
    {
        tmp->fgr_int = get_int(tmp->fgr_line);
        tmp = tmp->next;
        if (!(int_check((tmp))))
            return (NULL);
    }
    return (ok_fgr);
}