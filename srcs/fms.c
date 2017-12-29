/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fms.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:25:20 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:02:00 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_env	*init_move(t_env *l)
{
	t_road	*r;

	if (!(r = take_best_road(l)))
		put_error();
	ft_putstr(l->parse);
	free(l->parse);
	ft_putstr("\n");
	l = put_fms_start(l, r);
	l = move_fms(l);
	return (l);
}

int		check_end_fms(t_env *l)
{
	t_fms	*fs;

	fs = l->f;
	while (fs)
	{
		if (ft_strcmp(l->end, fs->location->node->name))
			return (0);
		fs = fs->next;
	}
	return (1);
}

int		can_move(t_env *l, t_fms *fs)
{
	t_fms	*fms;

	fms = l->f;
	if (!ft_strcmp(fs->location->node->name, l->end))
		return (2);
	if (fms == fs)
		return (1);
	while (fms->next != fs)
		fms = fms->next;
	if (fms->location != fs->location->next_node ||
			!ft_strcmp(l->end, fms->location->node->name))
		return (1);
	return (0);
}

t_fms	*reset_move(t_fms *fms)
{
	t_fms	*f;

	f = fms;
	while (f)
	{
		f->move = 0;
		f = f->next;
	}
	return (fms);
}

t_env	*move_fms(t_env *l)
{
	t_fms	*fs;
	int		ret;

	fs = l->f;
	while (fs)
	{
		if ((ret = can_move(l, fs)) == 1)
		{
			fs->move = 1;
			fs->location = fs->location->next_node;
		}
		else if (ret == 0)
			break ;
		fs = fs->next;
	}
	print_fourmis(l);
	l->f = reset_move(l->f);
	if (check_end_fms(l))
		return (l);
	else
		return (move_fms(l));
}
