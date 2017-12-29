/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 09:08:05 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:00:08 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(void)
{
	t_env	*l;

	l = NULL;
	l = parse_map(init_env(l));
	if (l->rebuilted == 0)
		put_error();
	if (!l->room->child->node)
		put_error();
	l = build_roads(l, l->room, NULL);
	l = init_move(l);
	destroy_all(l);
	return (0);
}

t_env	*parse_com(t_env *l, char *s)
{
	if (!ft_strcmp(s, "##start") && l->add == 0)
		l->add = 1;
	else if (!ft_strcmp(s, "##end") && l->add == 0)
		l->add = 2;
	else if (l->add > 0)
		put_error();
	return (l);
}

t_env	*parse_map(t_env *l)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (get_next_line(0, &ret))
	{
		l->parse = ft_strfjoin(ft_strfjoin(l->parse, ret), "\n");
		if (i++ == 0 && check_int(ret) && ft_atoi(ret) > 0)
			l->nb_fourmis = ft_atoi(ret);
		else if (ret[0] == '#')
			l = parse_com(l, ret);
		else if (check_spaces(ret))
			l = parse_room(l, ret);
		else if (check_mid(ret) && islink(l, ret))
			l = parse_link(l, ret);
		else
			break ;
		free(ret);
	}
	free(ret);
	return (l);
}

t_env	*parse_room(t_env *l, char *ret)
{
	t_link	*new;

	new = NULL;
	if (ft_strchr(ret, '-'))
		put_error();
	new = init_room(ret);
	new->next = l->room;
	l->room = new;
	if (l->add != 0)
	{
		if (!l->start && l->add == 1)
			l->start = ft_strdup(new->name);
		else if (!l->end && l->add == 2)
			l->end = ft_strdup(new->name);
		else
			put_error();
		l->add = 0;
	}
	return (l);
}

t_env	*parse_link(t_env *l, char *ret)
{
	char	**tmp;

	if (l->add == 1 || l->add == 2)
		put_error();
	tmp = ft_strsplit(ret, '-');
	l = create_tree(l, tmp);
	destroy_p(tmp);
	return (l);
}
