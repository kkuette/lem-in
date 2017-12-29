/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 10:19:52 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:06:58 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	put_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

t_env	*create_tree(t_env *l, char **link)
{
	if (l->rebuilted == 0)
		l = rebuilt_link(l);
	return (find_link(l, link));
}

void	destroy_fms(t_fms *f)
{
	t_fms	*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		free(tmp);
	}
	f = NULL;
}

int		road_len(t_env *l, t_road *r)
{
	t_road	*tmpr;
	int		len;

	len = 0;
	tmpr = r;
	while (tmpr)
	{
		len++;
		if (!ft_strcmp(l->end, tmpr->node->name))
			return (len);
		tmpr = tmpr->next_node;
	}
	return (0);
}
