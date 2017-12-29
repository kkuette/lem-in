/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 04:32:19 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:08:23 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_child	*add_to_last(t_child *s, t_child *n)
{
	t_child	*tmp;

	tmp = s;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	return (s);
}

t_road	*behind_last(t_road *road, t_road *last)
{
	t_road	*r;

	r = road;
	while (r->next_node != last)
		r = r->next_node;
	return (r);
}

t_child	*find_last(t_child *child, t_road *road)
{
	t_child	*tmp;

	tmp = child;
	while (tmp)
	{
		if (!ft_strcmp(tmp->node->name, road->node->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_road	*reset(t_road *road, t_road *last)
{
	t_road	*tmp;
	t_child	*reset;

	tmp = road;
	while (tmp->next_node != last && last != tmp && tmp)
	{
		reset = find_last(tmp->node->child, tmp->next_node);
		reset->mark = 0;
		tmp = tmp->next_node;
	}
	return (road);
}

t_link	*reset_mark(t_link *room, t_road *road)
{
	t_road	*r;

	r = NULL;
	while (r != road)
	{
		r = behind_last(road, r);
		if ((search_next_child(r->node->child)))
		{
			road = reset(road, r);
			break ;
		}
	}
	return (room);
}
