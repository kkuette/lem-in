/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:07:28 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:51:14 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_wchar(t_arg *l, wint_t value)
{
	int		size;
	int		ret;

	size = w_size(value);
	if (size <= 11)
		ret = mask_apply_1(value, size, l);
	else if (size <= 16)
		ret = mask_apply_2(value, l);
	else
		ret = mask_apply_3(value, l);
	return (ret);
}

int		print_wc(t_arg *l, va_list args)
{
	int		ret;

	ret = select_wchar(l, va_arg(args, wchar_t));
	choose_prec(l, l->w_save);
	return (ret);
}

int		print_ws(t_arg *l, va_list args)
{
	int			ret;
	wchar_t		*v;

	ret = 0;
	v = va_arg(args, wchar_t*);
	if (v == NULL)
		l->w_save = ft_strjoin(l->w_save, "(null)");
	else
		while (*v)
			ret = select_wchar(l, *v++);
	choose_prec(l, l->w_save);
	return (ret);
}
