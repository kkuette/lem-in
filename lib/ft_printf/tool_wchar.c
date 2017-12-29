/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:53:06 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:52:39 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		mask_apply_1(unsigned int n, int size, t_arg *l)
{
	t_w *w;

	if (!(w = malloc(sizeof(t_w*))))
		exit(0);
	w->mask_1 = 49280;
	if (size <= 7)
	{
		w->octet = n;
		l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	}
	else
	{
		w->oct_2 = (n << 26) >> 26;
		w->oct_1 = ((n >> 6) << 27) >> 27;
		w->octet = (w->mask_1 >> 8) | w->oct_1;
		l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
		w->octet = (w->mask_1 << 24) >> 24 | w->oct_2;
		l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	}
	return (w->ret);
}

int		mask_apply_2(unsigned int n, t_arg *l)
{
	t_w *w;

	if (!(w = malloc(sizeof(t_w*))))
		exit(0);
	w->mask_2 = 14712960;
	w->oct_3 = (n << 26) >> 26;
	w->oct_2 = ((n >> 6) << 26) >> 26;
	w->oct_1 = ((n >> 12) << 28) >> 28;
	w->octet = (w->mask_2 >> 16) | w->oct_1;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	w->octet = ((w->mask_2 << 16) >> 24) | w->oct_2;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	w->octet = ((w->mask_2 << 24) >> 24) | w->oct_3;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	return (w->ret);
}

int		mask_apply_3(unsigned int n, t_arg *l)
{
	t_w *w;

	if (!(w = malloc(sizeof(t_w*))))
		exit(0);
	w->mask_3 = 4034953344;
	w->oct_4 = (n << 26) >> 26;
	w->oct_3 = ((n >> 6) << 26) >> 26;
	w->oct_2 = ((n >> 12) << 26) >> 26;
	w->oct_1 = ((n >> 18) << 29) >> 29;
	w->octet = (w->mask_3 >> 24) | w->oct_1;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	w->octet = (w->mask_3 << 8) >> 24 | w->oct_2;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	w->octet = (w->mask_3 << 16) >> 24 | w->oct_3;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	w->octet = (w->mask_3 << 24) >> 24 | w->oct_4;
	l->w_save = ft_strjoin(l->w_save, ft_ctoa(w->octet));
	return (w->ret);
}

int		w_size(wint_t value)
{
	int	len;

	len = 0;
	while (value)
	{
		value /= 2;
		len++;
	}
	return (len);
}
