/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:51 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:16:42 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg		*search_prec(t_arg *l, const char *fmt, va_list args)
{
	if ((fmt[l->len_read] > '0' && fmt[l->len_read] <= '9') ||
			fmt[l->len_read] == '*')
		l->lenp = prec_d(l, fmt, args);
	if (fmt[l->len_read] == '.')
	{
		l->len_read++;
		l->point = 1;
		l->precision = prec_p(l, fmt, args);
	}
	return (l);
}

int			prec_p(t_arg *l, const char *fmt, va_list args)
{
	int		i;
	char	*prec;

	i = 0;
	prec = NULL;
	if (fmt[l->len_read] == '*')
	{
		l->len_read++;
		i = va_arg(args, int);
		if (i < 0)
		{
			l->point = 0;
			return (-1);
		}
		return (i);
	}
	while (ft_isdigit(fmt[i + l->len_read]))
		i++;
	if (i != 0)
		prec = ft_strsub(fmt, l->len_read, i);
	l->len_read += i;
	if (prec)
		return (ft_atoi(prec));
	return (0);
}

int			prec_d(t_arg *l, const char *fmt, va_list args)
{
	int		i;
	char	*prec;

	prec = NULL;
	i = 0;
	while (ft_isdigit(fmt[i + l->len_read]) == 1)
		i++;
	if (fmt[l->len_read + i] == '*')
		return (prec_wild(l, fmt, args, i));
	prec = ft_strsub(fmt, l->len_read, i);
	l->len_read += i;
	return (ft_atoi(prec));
}

int			prec_wild(t_arg *l, const char *fmt, va_list args, int i)
{
	int		j;
	char	*prec;

	j = 0;
	prec = NULL;
	l->len_read += i + 1;
	j = va_arg(args, int);
	if (j < 0 && !ft_strchr(l->flags, '-'))
		l->flags = ft_strjoin(l->flags, "-");
	if (j < 0)
		j *= -1;
	if ((fmt[l->len_read] > '0' && fmt[l->len_read] <= '9'))
	{
		while (ft_isdigit(fmt[i + l->len_read]) == 1)
			i++;
		prec = ft_strsub(fmt, l->len_read, i);
		l->len_read += i;
	}
	if (j == 0 && !ft_strchr(l->flags, '0') && !prec)
		l->flags = ft_strjoin(l->flags, "0");
	if (prec)
		j += ft_atoi(prec);
	return (j);
}
