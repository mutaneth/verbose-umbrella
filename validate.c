/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:49:57 by hfalmer           #+#    #+#             */
/*   Updated: 2019/07/24 19:45:14 by hfalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** FREE WHEN NULL ty
** fgr_new: creates new node in t_fgr. chr starts with 65 and then goes up to 90
*/

int		int_check(t_fgr *fgr)
{
	t_fgr	*tmp;
	int		f;

	tmp = fgr;
	while (tmp)
	{
		f = tmp->fgr_int;
		if ((f != 4369) && (f != 15) && (f != 547) && (f != 29) &&
			(f != 785) && (f != 23) && (f != 275) && (f != 71) &&
			(f != 401) && (f != 113) && (f != 51) && (f != 99) &&
			(f != 153) && (f != 57) && (f != 305) && (f != 39) &&
			(f != 281) && (f != 27) && (f != 561))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_fgr	*mega_fgr_val(int fd)
{
	t_fgr	*ok_fgr;
	t_fgr	*tmp;
	char	*line;

	ok_fgr = NULL;
	if (!(ok_fgr = after_line(fd, &line)))
	{
		return (NULL);
	}
	tmp = ok_fgr;
	while (tmp)
	{
		if (!(fgrl_xtra_01((tmp->fgr_line))))
			return (NULL);
		tmp->fgr_int = ft_fgr_int(tmp->fgr_line);
		tmp = tmp->next;
	}
	tmp = ok_fgr;
	if (!(int_check(tmp)))
	{
		free_fgr(ok_fgr);
		free(line);
		return (NULL);
	}
	free(line);
	return (ok_fgr);
}

void	free_fgr(t_fgr *fgr)
{
	t_fgr *tmp;

	if (fgr)
	{
		while (fgr)
		{
			tmp = fgr->next;
			if (fgr->fgr_line)
				free(fgr->fgr_line);
			free(fgr);
			fgr = tmp;
		}
	}
}

char	*ft_fgr_line(int fd)
{
	int		i;
	char	*tmp;
	char	*fgrl;
	int		gr;
	char	*tfl;

	i = -1;
	fgrl = ft_strnew(0);
	while (++i < 4 && (gr = get_next_line(fd, &tmp)) == 1)
	{
		if (!tmp)
		{
			return (NULL);
		}
		if (ft_strlen(tmp) == 4)
		{
			tfl = ft_strrejoin(fgrl, tmp, 0);
			fgrl = tfl;
		}
		else
		{
			if (tmp)
				free(tmp);
			return (NULL);
		}
	}
	if (i != 4)
		if (gr != 1)
		{
			free(tfl);
			return (NULL);
		}
	return (fgrl);
}

t_fgr	*fgr_new(char fgr_chr, char *line)
{
	t_fgr *fgr;

	if (!line || !(fgr = (t_fgr*)malloc(sizeof(t_fgr))))
		return (NULL);
	fgr->fgr_int = -1;
	fgr->fgr_chr = fgr_chr;
	fgr->fgr_line = ft_strdup(line);
	fgr->next = NULL;
	return (fgr);
}
