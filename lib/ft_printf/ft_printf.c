/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:40:50 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:15:15 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = searchp(format, args);
	}
	va_end(args);
	return (len);
}

int		searchp(const char *format, va_list args)
{
	t_arg	*l;
	int		len;

	len = 0;
	l = NULL;
	l = crt_lst(l);
	while (format[l->len_read])
	{
		if (format[l->len_read] == '%')
		{
			if ((parse(format, args, l)) == -1)
				return (-1);
		}
		else
		{
			write(1, &format[l->len_read], 1);
			l->str_len++;
		}
		l->len_read++;
	}
	len = l->str_len;
	free(l);
	return (len);
}

int		parse(const char *fmt, va_list args, t_arg *l)
{
	int		len;

	l->len_read++;
	len = 0;
	l = search_flags(l, fmt);
	l = search_prec(l, fmt, args);
	l = search_lenm(l, fmt);
	l = search_conv(l, fmt);
	if (l->conv[0] == '\0')
		return (-1);
	select_print(l, args);
	lst_reset(l);
	return (len);
}

void	lst_reset(t_arg *l)
{
	l->precision = 0;
	l->point = 0;
	l->neg = 0;
	l->lenp = 0;
	if (l->w_save)
		free(l->w_save);
	l->w_save = NULL;
	if (l->conv[0] != '\0')
		l->conv[0] = '\0';
	if (l->flags[0] != '\0')
		l->flags[0] = '\0';
	if (l->lenmod[0] != '\0')
		l->lenmod[0] = '\0';
}
