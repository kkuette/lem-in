/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:02:11 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 11:20:31 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_env	*rebuilt_link(t_env *l)
{
	t_link	*tmp;

	tmp = l->room;
	if (!l->end || !l->start)
		put_error();
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, l->start) && l->rebuilted == 0)
			l = build_start(l, tmp);
		if (!ft_strcmp(tmp->name, l->end) && l->rebuilted == 1)
			l = build_end(l, tmp);
		tmp = tmp->next;
	}
	return (l);
}

t_env	*build_start(t_env *l, t_link *start)
{
	t_link	*tmp;

	tmp = l->room;
	l->rebuilted = 1;
	if (tmp == start)
		return (l);
	while (tmp->next != start)
		tmp = tmp->next;
	tmp->next = start->next;
	start->next = l->room;
	l->room = start;
	return (l);
}

t_env	*build_end(t_env *l, t_link *end)
{
	t_link	*tmp;

	l->rebuilted = 2;
	tmp = l->room;
	while (tmp->next != end)
		tmp = tmp->next;
	tmp->next = end->next;
	if (end->next)
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
	return (l);
}

t_env	*find_link(t_env *l, char **link)
{
	t_link	*start;
	t_link	*end;

	start = l->room;
	end = l->room;
	while (start)
	{
		if (!ft_strcmp(start->name, link[0]))
		{
			while (end)
			{
				if (!ft_strcmp(end->name, link[1]))
					return (add_link(start, end, l));
				end = end->next;
			}
		}
		start = start->next;
	}
	return (l);
}

t_env	*add_link(t_link *start, t_link *end, t_env *l)
{
	t_child	*child;

	child = NULL;
	if (start->child->node)
	{
		child = init_child();
		child->node = end;
		start->child = add_to_last(start->child, child);
	}
	else
		start->child->node = end;
	if (end->child->node)
	{
		child = init_child();
		child->node = start;
		end->child = add_to_last(end->child, child);
	}
	else
		end->child->node = start;
	return (l);
}
