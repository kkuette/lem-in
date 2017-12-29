/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:51:34 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/07 05:35:09 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_env	*calc_all_lenroad(t_env *l)
{
	t_road	*tmp;

	tmp = l->road;
	while (tmp)
	{
		tmp->roadlen = road_len(l, tmp);
		tmp = tmp->next_road;
	}
	return (l);
}

t_road	*search_best(t_env *l, int n)
{
	t_road	*tmp;

	tmp = l->road;
	while (tmp)
	{
		if (tmp->roadlen == n)
			break ;
		tmp = tmp->next_road;
	}
	return (tmp);
}

t_road	*take_best_road(t_env *l)
{
	t_road	*tmp;
	int		best;

	l = calc_all_lenroad(l);
	best = 999999;
	tmp = l->road;
	while (tmp)
	{
		if (tmp->roadlen > 0 && tmp->roadlen < best)
			best = tmp->roadlen;
		tmp = tmp->next_road;
	}
	return (search_best(l, best));
}

t_env	*put_fms_start(t_env *l, t_road *r)
{
	t_fms	*new;
	int		i;

	i = l->nb_fourmis;
	while (i > 0)
	{
		new = init_fms(i, r);
		new->next = l->f;
		l->f = new;
		i--;
	}
	return (l);
}
