/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 10:23:33 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/06 03:40:38 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		check_spaces(char *s)
{
	int		ret;

	ret = 0;
	while (*s++)
		if (*s == ' ')
			ret++;
	if (ret == 2)
		return (1);
	return (0);
}

int		check_int(char *s)
{
	if (ft_strlen(s) == ft_nbrlen(ft_atoi(s)))
		return (1);
	return (0);
}

int		check_mid(char *s)
{
	int		ret;

	ret = 0;
	while (*s++)
		if (*s == '-')
			ret++;
	if (ret != 1)
		return (0);
	return (1);
}

int		islink(t_env *l, char *s)
{
	t_link	*tmpl;
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	tmpl = l->room;
	tmp = ft_strsplit(s, '-');
	while (tmpl)
	{
		if (!ft_strcmp(tmp[0], tmpl->name) ||
				!ft_strcmp(tmp[1], tmpl->name))
			i++;
		tmpl = tmpl->next;
	}
	destroy_p(tmp);
	if (i != 2)
		return (0);
	return (1);
}
