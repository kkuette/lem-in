/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:30 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:59:00 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg		*search_conv(t_arg *l, const char *fmt)
{
	char	*arg_type;
	int		i;

	i = -1;
	arg_type = "sSpbdDioOuUxXcC%";
	while (arg_type[++i])
	{
		if (ft_charcmp(arg_type[i], fmt[l->len_read]) == 0)
		{
			l->conv = ft_strsub(arg_type, i, 1);
			break ;
		}
	}
	return (l);
}
