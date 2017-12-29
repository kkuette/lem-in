/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 09:40:27 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:03:06 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_env	*init_env(t_env *l)
{
	if (!(l = (t_env*)malloc(sizeof(t_env))))
		exit(0);
	l->room = NULL;
	l->path = NULL;
	l->road = NULL;
	l->f = NULL;
	l->start = NULL;
	l->end = NULL;
	l->parse = NULL;
	l->add = 0;
	l->nb_fourmis = 0;
	l->rebuilted = 0;
	return (l);
}

t_child	*init_child(void)
{
	t_child	*ret;

	ret = NULL;
	if (!(ret = (t_child*)malloc(sizeof(t_child))))
		exit(0);
	ret->mark = 0;
	ret->next = NULL;
	ret->node = NULL;
	return (ret);
}

t_road	*init_road(void)
{
	t_road	*new;

	new = NULL;
	if (!(new = (t_road*)malloc(sizeof(t_road))))
		exit(0);
	new->roadlen = 0;
	new->node = NULL;
	new->next_node = NULL;
	new->next_road = NULL;
	return (new);
}

t_link	*init_room(char *s)
{
	t_link	*new;
	char	**tmp;

	new = NULL;
	tmp = ft_strsplit(s, ' ');
	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	new->name = ft_strdup(tmp[0]);
	if (!check_int(tmp[1]) || !check_int(tmp[2]))
		put_error();
	new->x = ft_atoi(tmp[1]);
	new->y = ft_atoi(tmp[2]);
	new->child = init_child();
	new->isfourmis = 0;
	new->ispass = 0;
	new->next = NULL;
	destroy_p(tmp);
	return (new);
}

t_fms	*init_fms(int n, t_road *r)
{
	t_fms	*new;

	new = NULL;
	if (!(new = (t_fms*)malloc(sizeof(t_fms))))
		exit(0);
	new->num = n;
	new->move = 0;
	new->location = r;
	new->next = NULL;
	return (new);
}
