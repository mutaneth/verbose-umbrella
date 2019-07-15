/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/10 19:28:18 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"/*
int			check_input_count(char *blc) //check for wrong chars and extra #
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
	if (sharp != 4)
		return(404);
	return (1);
}*/
//	GNL returns 0 after 1 f read *****************
char			*ft_fgr_line(int fd)// malloc??
{
	int i;
	char *tmp;
	char *fgrl;
	int gr;

	i = -1;
	fgrl = "";
	while(++i < 4 && (gr =get_next_line(fd, &tmp)) == 1)
	{
//		printf(" gr=%d ", ++gr);
		if (!tmp)
		{
			printf("kek");
			return (NULL);
		}
//		printf(" tmp_gnl=%s\n", tmp);
		if (ft_strlen(tmp) == 4)
			fgrl = ft_strrejoin(fgrl, tmp, 1);//ft_strrejoin(tmp, fgrl, -1);
		else
		{
			if (tmp)
				free(tmp);
		//	if (fgrl) free(fgrl); //////////expresion has occured
			return (NULL);//free fgrl?
		}
	}
//	printf(" gr=%d ", gr);
//	if (fgrl) free(fgrl); //////////
	if (i != 4 )
		if ( gr != 1)//i=gnl?
		return (NULL);//this part needs to be fixed
		printf(" fgrl=%s\n", fgrl);
	return (fgrl);
}
 /*
char		*ft_fgr_line(int fd)// malloc??
{
	int i;
	char *tmp;
	char *fgrl;
	int ret;
	char bug[6];// * buf?

	i = -1;
	fgrl = "";
	while( ret = read(fd, bug, 5) == 5)
	{
		if (buf[4] != '\n')
			return (NULL);
		bug[5] = '\0';
		fgrl = ft_strrejoin(fgrl, buf);
	printf(" fgrl=%s\n", fgrl);
	return (fgrl);
}*/

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

	printf(" push_back1: %c ", /* (int)*/i);
	if (!(*begin_list))
	{
		*begin_list = fgr_new(i, data);
		return ;
	}
	tmp = *begin_list;
//	printf("push_back2: %d\n", (int)i);
//	printf("FFFFFFF");
//	printf("\n pbtmp=%d WTF !!!!!!!!!!!!!!!!", tmp->fgr_chr);
	while (tmp->next)
	{
		printf(" pbtmp=%d !", tmp->fgr_chr);
		tmp = tmp->next;
	}
//	printf("push_back3: %d\n", (int)i);
	tmp->next = fgr_new(i, data);
//	printf("push_back4: %d\n", (int)i);
//	return (*begin_list);
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
	printf(" fd-al=%d ", fd);
	printf(" buf=5%s-", buf);
	printf(" buf[0]=%c, buf[1]=%c, nuf[2]=-", buf[0], buf[1]);
	while ((line = ft_fgr_line(fd)) && ++i < 'Z')
	{
	//	check = read(fd, buf, 1);
//		printf(" chred=%d ", check);
		if (((check = read(fd, buf, 1)) == 1))
			if (buf[0] != '\n')
			{
				printf(" buf[0]=%c-", buf[0]);
				return (NULL);// free
			}
		buf[1] = '\0';
//		printf(" checl=%d ", check);
		printf(" buf=%s-", buf);
		if (check == 0)
		{
			fgr_push_back(&fgr, line, (char)i);
			break ;//????????? last fgr
		}
		printf("i=%c-", (char)i);
		if (check)
			fgr_push_back(&fgr, line, (char)i);
	}
	if (!line)	//if line = 0 free fgr lst
		free_fgr(&fgr);
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
		if (frst == -1 && fgrl[i] - '0' == 1)
			frst = i;
		if (frst != -1)
			fgr_int |= (fgrl[i] - '0') << (i - frst);
	//	ft_print_bits(fgr_int);
	//	printf("f_i=%d ", fgr_int);
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
	printf(" fd-mgdfdl=%d ", fd);
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
	t_fgr *ttmp;
	ttmp = ok_fgr;
	while (ttmp)
	{
		printf(" t_mp->fgr_int=%d ", ttmp->fgr_int);
		ttmp = ttmp->next;

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
//		free(*fgr);
//		free(fgr);
	}
}
