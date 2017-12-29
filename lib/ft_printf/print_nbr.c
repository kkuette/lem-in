/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:16:14 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:53:19 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			print_nbr(t_arg *l, va_list args)
{
	int			ret;
	char		*v;

	v = choose_type(l, args);
	if (l->point == 1 && l->precision == 0 && v[0] == '0' && v[1] == '\0')
		v[0] = '\0';
	ret = 0;
	v = is_neg(v, l);
	choose_prec(l, v);
	return (ret);
}

int			print_unbr(t_arg *l, va_list args)
{
	int		ret;
	char	*v;

	v = choose_utype(l, args, 10);
	if (l->point == 1 && l->precision == 0 && v[0] == '0' && v[1] == '\0')
		v[0] = '\0';
	ret = 0;
	choose_prec(l, v);
	return (ret);
}

char		*choose_type(t_arg *l, va_list args)
{
	if (!ft_strcmp(l->lenmod, "ll"))
		return (ft_imtoa(va_arg(args, long long)));
	if (l->lenmod[0] == 'l' || l->conv[0] == 'D')
		return (ft_imtoa(va_arg(args, long)));
	if (l->lenmod[0] == 'j')
		return (ft_imtoa(va_arg(args, intmax_t)));
	if (!ft_strcmp(l->lenmod, "hh"))
		return (ft_itoa((char)va_arg(args, int)));
	if (l->lenmod[0] == 'h' && ft_strcmp(l->lenmod, "hh"))
		return (ft_itoa((short)va_arg(args, int)));
	if (l->lenmod[0] == 'z')
		return (ft_imtoa(va_arg(args, size_t)));
	return (ft_itoa(va_arg(args, int)));
}

char		*choose_utype(t_arg *l, va_list args, int base)
{
	if (!ft_strcmp(l->lenmod, "ll"))
	{
		return (ft_uintmtoa_base(va_arg(args, unsigned long long), base,
		l->conv));
	}
	if (l->lenmod[0] == 'l' || l->conv[0] == 'U' || l->conv[0] == 'O')
		return (ft_uintmtoa_base(va_arg(args, unsigned long), base, l->conv));
	if (l->lenmod[0] == 'j')
		return (ft_uintmtoa_base(va_arg(args, uintmax_t), base, l->conv));
	if (!ft_strcmp(l->lenmod, "hh"))
	{
		return (ft_uctoa((unsigned char)va_arg(args, unsigned int), base,
		l->conv));
	}
	if (l->lenmod[0] == 'h' && l->lenmod[1] == '\0')
	{
		return (ft_uinttoa((unsigned short)va_arg(args, unsigned int), base,
		l->conv));
	}
	if (l->lenmod[0] == 'z' || l->conv[0] == 'p')
		return (ft_uintmtoa_base(va_arg(args, size_t), base, l->conv));
	return (ft_uinttoa(va_arg(args, unsigned int), base, l->conv));
}

char		*is_neg(char *n, t_arg *l)
{
	if (ft_strchr(n, '-'))
	{
		l->neg = 1;
		n = ft_strsub(n, 1, ft_strlen(n) - 1);
	}
	return (n);
}
