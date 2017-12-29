/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 19:35:34 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/07 04:32:04 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	destroy_child(t_child *l)
{
	t_child	*tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp);
		tmp = NULL;
	}
}

void	destroy_road(t_road *r)
{
	t_road	*tmp;
	t_road	*tmpr;

	while (r)
	{
		tmp = r;
		r = r->next_road;
		while (tmp)
		{
			tmpr = tmp;
			tmp = tmp->next_node;
			free(tmpr);
			tmpr = NULL;
		}
	}
}

void	destroy_node(t_link *l)
{
	t_link	*tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l;
		destroy_child(l->child);
		free(l->name);
		l = l->next;
		free(tmp);
	}
}

void	destroy_all(t_env *l)
{
	destroy_node(l->room);
	destroy_road(l->road);
	destroy_fms(l->f);
	free(l->start);
	free(l->end);
	free(l);
}

void	destroy_p(char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}
