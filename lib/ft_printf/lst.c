/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:46 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:57:42 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg		*crt_lst(t_arg *l)
{
	if (!(l = malloc(sizeof(t_arg))))
		exit(0);
	if (!(l->flags = (char*)malloc(sizeof(char) + 1)))
		exit(0);
	if (!(l->lenmod = (char*)malloc(sizeof(char) + 1)))
		exit(0);
	l->conv = "\0";
	l->flags = "\0";
	l->lenmod = "\0";
	l->len_read = 0;
	l->str_len = 0;
	l->str_saved = NULL;
	l->w_save = NULL;
	return (l);
}
