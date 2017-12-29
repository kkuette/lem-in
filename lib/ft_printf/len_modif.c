/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:37 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:57:57 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg		*search_lenm(t_arg *l, const char *fmt)
{
	if (fmt[l->len_read] == 'h' && fmt[l->len_read + 1] == 'h')
	{
		l->lenmod = ft_strdup("hh");
		l->len_read++;
	}
	if (fmt[l->len_read] == 'h' && l->lenmod[0] == '\0')
		l->lenmod = ft_strdup("h");
	if (fmt[l->len_read] == 'l' && fmt[l->len_read + 1] == 'l')
	{
		l->lenmod = ft_strdup("ll");
		l->len_read++;
	}
	if (fmt[l->len_read] == 'l' && l->lenmod[0] == '\0')
		l->lenmod = ft_strdup("l");
	if (fmt[l->len_read] == 'j')
		l->lenmod = ft_strdup("j");
	if (fmt[l->len_read] == 'z')
		l->lenmod = ft_strdup("z");
	if (l->lenmod[0] != '\0')
		l->len_read++;
	return (l);
}
