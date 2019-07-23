/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/16 23:12:30 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//	GNL returns 0 after 1 f read *****************
char			*ft_fgr_line(int fd)
{
	int		i;
	char	*tmp;
	char	*fgrl;
	int		gr;
	char	*tfl;

	i = -1;
	fgrl = ft_strnew(0);//"";
//	tfl = fgrl;
	while (++i < 4 && (gr = get_next_line(fd, &tmp)) == 1)
	{
		if (!tmp)
		{
			return (NULL);
		}
		if (ft_strlen(tmp) == 4)
		{
		//	if (fgrl == NULL)
		//	fgrl = ft_strnew(0);
			tfl = ft_strrejoin(fgrl, tmp, 0);
		//	free(fgrl);
			fgrl = tfl;
		}
		else
		{
			if (tmp)
				free(tmp);
			return (NULL);//free fgrl?
		}
	}
	if (i != 4)
		if (gr != 1)//i=gnl?
		{
			free(tfl);
			return (NULL);//this part needs to be fixed
		}
	//	printf(" fgrl=%s\n", fgrl);
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
	if (!line)
		return (NULL);
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
	{
		tmp = tmp->next;
	}
	tmp->next = fgr_new(i, data);
	free(tmp);
//	return (*begin_list);
}

t_fgr		*after_line(int fd, char **line)/* just check \n and \0 yuhoo and fill the fgr*/
{
//	char	*tline;
	int		i;
	char	buf[2];
	int		check;
	t_fgr	*fgr;

	fgr = NULL;
	i = 'A' - 1;
//	tline = *line;
	while ((*line = ft_fgr_line(fd)) && ++i < 'Z')
	{
		if (((check = read(fd, buf, 1)) == 1))
			if (buf[0] != '\n')
			{
				free(*line);
				return (NULL);// free
			}
		buf[1] = '\0';
		if (check == 0)
		{
			fgr_push_back(&fgr, *line, (char)i);
		//	free(*line);
			break ;//????????? last fgr
		}
		if (check)
			fgr_push_back(&fgr, *line, (char)i);
		free(*line);
	}
	if (!(*line))	//if line = 0 free fgr lst
	{
		free_fgr(&fgr);
		free(*line);
	}
//	if (*line)
//		free(*line);
	return (fgr);
}

int			check_n(int fd)
{
	char buf[22];
	int ret;

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

int			fgrl_xtra_01(char *fgr_line)/* checks if this line is valid and change symbols to 1 or 0. if it's not val, just frees*/
{
	int	i;
	int	l;
	int b;

	l = ft_strlen(fgr_line);
	if (l != 16)
		return (0);
	i = -1;
	b = 0;
	while (++i < l)
	{
		if (fgr_line[i] != '.' && fgr_line[i] != '#')
			//free(fgr_l);
			return (0);
		if (fgr_line[i] == '.')
			fgr_line[i] = '0';
		else
		{
			fgr_line[i] = '1';
		}
	}
	return (1);
}

int			ft_fgr_int(char *fgrl)/* takes fgrl and turns it to int using bits logic after fgrl_val*/
{
	int	fgr_int;
	int	frst;
	int	i;

	fgr_int = 0;
	frst = -1;
	i = -1;
	while (++i < 16)
	{
		if (frst == -1 && fgrl[i] - '0' == 1)
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
	while (tmp)
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
	char *line; //unused variabel

	ok_fgr = NULL;
	if (!(ok_fgr = after_line(fd, &line)))
	{
	//	free(line);
		return (NULL);
	}
	tmp = ok_fgr;
	while (tmp)
	{
		if (!(fgrl_xtra_01((tmp->fgr_line))))
			return (NULL);// free
//		printf("xtra:%s\n", tmp->fgr_line);
		tmp->fgr_int = ft_fgr_int(tmp->fgr_line);
//		printf("int:%d ", tmp->fgr_int);
		tmp = tmp->next;
	}
	tmp = ok_fgr;
	if (!(int_check(tmp)))
	{// free
		free_fgr(&ok_fgr);//68-17--- 44/0
		free(line);//44:0 --> 27:0
		return (NULL);
	}
	free(line);
	return (ok_fgr);
}

void		free_fgr(t_fgr **fgr)
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
//		free(fgr);
	}
}
