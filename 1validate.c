/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/06/25 18:16:28 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*  int			check_input_count(char *blc) //check for wrong chars and extra #
{
	int i;
	int sharp;

	i = -1;
//	while (str[++i] && (str[++i] == '\n' || str[++i] == '#' || str[++i] == '.'));
	while (blcstr[++i])
	{
		if (blcstr[i] != '\n' && blcstr[i] != '#' && blcstr[i] != '.')
			return (0);
		sharp = 0;
		if (blcstr[i] == '#' && ++sharp > 4)
			return (0);
	}
	return (1);
}
*/

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
			fgrl = /*ft_strrejoin(fgrl, tmp, 1);*/ft_strrejoin(tmp, fgrl, -1);
		else
		{
			if (tmp)
				free(tmp);
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

	fgr = (t_fgr*)malloc(sizeof(t_fgr));
	fgr->fgr_int = -1;
	fgr->fgr_chr = fgr_chr;
	fgr->fgr_line = ft_strdup(line);
	fgr->next = NULL;
	return (fgr);
}

/* t_fgr			*fgr_lst(char i, char *line, t_fgr *fgr)
{
	t_fgr *tmp;

	if (!fgr)
		fgr_new(i, line);
	else
	{
		tmp = fgr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = fgr_new(i, line);
	}
	return (fgr);
}*/

/*t_fgr			*after_line(int fd)/ * \n between figures && no symbols after \0 EOF && EOF after figures * /
{
	char	i;
	char	buf[2];//SIZE NEEDED!
	t_fgr	*fgr;
	t_fgr	*tmpf;
	char *line;//line where

//	tmpf = fgr;
	i = 'A' - 1;
	printf("WHYSEGA?"); //SEGAA>>>????
	while ((line = ft_fgr_line(fd)) && ++i < 'Y') //if
	{
		if (!fgr)
			fgr = fgr_new(i, line);
		else
		{
			tmpf = fgr;
			tmpf = fgr_lst(i, line, fgr);
		}
		read(fd, buf, 1);
//		buf[1] = '\0';
		printf("buf=%s", buf);
//		printf("buf[0] =%c", buf[0]);
		if (buf[0] == '\0')
			break ;
		if (buf[0] != '\n')
			return (NULL);//free 
	}
	printf("buf[0] =%c\n", buf[0]);
	if ( / * buf[0] && * /buf[0] == '\0' && read(fd, buf, 1) == 1)
		return (0);
/ *	else
		return (NULL); // if null ? else null?
	if (ft_fgr_line(fd))
		return (NULL); * /
	return (fgr);
}*/

void	fgr_push_back(t_fgr **begin_list, char *data, char i)
{
	t_fgr	*tmp;

//	printf("push_back1: %d\n", (int)i);
	if (!(*begin_list))
	{
		*begin_list = fgr_new(i, data);
		return ;
	}
	tmp = *begin_list;
//	printf("push_back2: %d\n", (int)i);
	while (tmp->next)
		tmp = tmp->next;
//	printf("push_back3: %d\n", (int)i);
	tmp->next = fgr_new(i, data);
//	printf("push_back4: %d\n", (int)i);
//	return (*begin_list);
}

t_fgr		*after_line(int fd)/* just check \n and \0 yuhoo and fill the fgr*/
{
	char	*line;
	int		i;
	char	buf[2];
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

int     check_n(int fd)
{
    char    buf[22];
    int     ret;

    while ((ret = read(fd, buf, 21)) == 21)
    {
        buf[21] = '\0';
        if (buf[20] && buf[20] != '\n')
            return(0);/* no \n */
    }
    if (ret == 20)
        return (1);
    else
        return(0);/* bad fgr */
}

int		fgrl_xtra_01(char *fgr_line)/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
{
	int	i;
	int	l;

	l = ft_strlen(fgr_line);
	if (l != 16)
		return (0);
	i = -1;
	while (++i < l)
	{
		if (fgr_line[i] != '.' && fgr_line[i] != '#')
			//free(fgr_l);
			return (0);
		if (fgr_line[i] == '.')
			fgr_line[i] = '0';
		else
			fgr_line[i] = '1';
	}
	return (1);
}

int		ft_fgr_int(char *fgrl)/* takes fgrl and turns it to int using bits logic after fgrl_val*/
{
	int	fgr_int;
	int	frst;
	int	i;

	fgr_int = 0;
	frst = -1;
	i = -1;
	while (++i < 16)
	{
		if (frst == -1)
			if (fgrl[i] - '0' == 1)
				frst = i;
		if (frst != -1)
			fgr_int |= (fgrl[i] - '0') << (i - frst);
	}
	return (fgr_int);
}

int			int_check(t_fgr *fgr)
{
	t_fgr	*tmp;
	int		f;

	tmp = fgr;
	while (tmp)// 1 elem?
	{
		f = tmp->fgr_int;
		if ((f != 4369) && (f != 15) && (f != 547) && (f != 29) 
		&& (f != 785) && (f != 23) && (f != 275) && (f != 71) && (f != 401) 
		&& (f != 113) && (f != 51) && (f != 99) && (f != 153) && (f != 57) 
		&& (f != 305) && (f != 39) && (f != 281) && (f != 27) && (f != 561))
			 return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_fgr			*mega_fgr_val(int fd)
{
	t_fgr *ok_fgr;
	t_fgr *tmp;
//	char *line; //unused variabel

	ok_fgr = NULL;
	if (!(ok_fgr = after_line(fd)))
	{
		printf("bad");
		return (NULL);
	}
 	tmp = ok_fgr;
	while (tmp)
	{
		if (!(fgrl_xtra_01((tmp->fgr_line))))
			return (NULL);// free
		printf("xtra:%s\n", tmp->fgr_line);
		tmp->fgr_int = ft_fgr_int(tmp->fgr_line);
		printf("int:%d ", tmp->fgr_int);
		tmp = tmp->next;
	}
	tmp = ok_fgr;
//	printf("i_ch=%d", int_check(tmp));	////////////
	if (!(int_check(tmp)))
	{
		printf("rr-intcheck\n");
		return (NULL);// free
	}
	return (ok_fgr);
}

void	free_fgr(t_fgr **fgr)
{
	t_fgr *tmp;
	t_fgr *t;

	if (fgr)
	{
		tmp = *fgr;
		while (tmp)
		{
			if (tmp->fgr_line)
				free((void*)tmp->fgr_line);
			t = tmp;
			tmp = tmp->next;
			t->next = NULL;
			free(t);
		}
		free(tmp);
		free(*fgr);
		free(fgr);
	}
}