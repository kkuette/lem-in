/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:02:28 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:37:18 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_gnl	*add_line(t_gnl *tmp)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		rded;

	rded = 0;
	ret = read(tmp->fds, buff, BUFF_SIZE);
	tmp->rs = ret;
	if (tmp->rs < 0)
		return (tmp);
	buff[ret] = '\0';
	tmp->saved_readed = ft_strfjoin(tmp->saved_readed, buff);
	while (tmp->saved_readed[rded] != '\n' && tmp->saved_readed[rded] != '\0')
		rded++;
	tmp->readed_c = rded;
	if (tmp->saved_readed[rded] != '\n' && ret)
		return (add_line(tmp));
	return (tmp);
}

static t_gnl	*lst_chr(const int fd)
{
	static	t_gnl	*l = NULL;
	t_gnl			*tmp;

	tmp = l;
	while (tmp)
	{
		if (tmp->fds == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_gnl *)malloc(sizeof(t_gnl));
	tmp->fds = fd;
	tmp->saved_readed = NULL;
	tmp->next = l;
	l = tmp;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	t_gnl	*tmp;
	char	*t;

	t = NULL;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	tmp = add_line(lst_chr(fd));
	if (tmp->rs < 0)
		return (-1);
	*line = ft_strsub(tmp->saved_readed, 0, tmp->readed_c);
	if (tmp->saved_readed[0] == '\0')
		return (0);
	t = tmp->saved_readed;
	if (tmp->saved_readed[tmp->readed_c] == '\n')
	{
		tmp->saved_readed = ft_strdup(&(tmp->saved_readed)[tmp->readed_c + 1]);
		free(t);
	}
	else
		tmp->saved_readed[0] = '\0';
	return (1);
}
