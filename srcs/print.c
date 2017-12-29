/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:02:13 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 11:56:20 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		is_last(t_fms *f)
{
	t_fms *tmp;

	tmp = f;
	while (tmp)
	{
		if (tmp->move == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_fourmis(t_env *l)
{
	t_fms	*tmp;

	tmp = l->f;
	while (tmp)
	{
		if (tmp->move == 1)
		{
			ft_putchar('L');
			ft_putnbr(tmp->num);
			ft_putchar('-');
			ft_putstr(tmp->location->node->name);
			if (!is_last(tmp->next))
				ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
