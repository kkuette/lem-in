/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_roads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:05:25 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 11:56:06 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		check_exist(t_link *l, t_road *r)
{
	t_road	*tmpr;

	tmpr = r;
	if (!l)
		return (0);
	while (tmpr)
	{
		if (!ft_strcmp(tmpr->node->name, l->name))
			return (0);
		tmpr = tmpr->next_node;
	}
	return (1);
}

t_road	*add_node(t_road *r, t_link *l)
{
	t_road	*new;
	t_road	*tmpr;

	tmpr = r;
	new = init_road();
	new->node = l;
	if (!tmpr)
		return (new);
	while (tmpr->next_node)
		tmpr = tmpr->next_node;
	tmpr->next_node = new;
	new = r;
	return (new);
}

t_child	*search_next_child(t_child *c)
{
	t_child	*tmp;

	tmp = c;
	while (tmp)
	{
		if (tmp->mark == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_env	*build_roads(t_env *l, t_link *node, t_road *r)
{
	t_child	*tmp;

	tmp = node->child;
	while (tmp)
	{
		if (check_exist(tmp->node, r) && tmp->mark == 0)
		{
			tmp->mark = 1;
			return (build_roads(l, tmp->node, add_node(r, node)));
		}
		tmp = tmp->next;
	}
	r = add_node(r, node);
	r->next_road = l->road;
	l->road = r;
	l->room = reset_mark(l->room, r);
	if (search_next_child(l->room->child))
		return (build_roads(l, l->room, NULL));
	return (l);
}
