/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:25:20 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:17:32 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	choose_prec(t_arg *l, char *arg)
{
	if (l->point == 1)
		arg = print_prec(l, arg);
	if ((l->conv[0] == 'c' || l->conv[0] == 'C') && arg[0] == '\0')
	{
		l->lenp--;
		l->str_len++;
	}
	l->lenp -= ft_strlen(arg);
	l->str_len += ft_strlen(arg);
	if (ft_strchr(l->flags, '0'))
		apply_flags_s(l, arg);
	if (!ft_strchr(l->flags, '-') && l->lenp > 0)
		print_lenf(l);
	if (!ft_strchr(l->flags, '0'))
		apply_flags_s(l, arg);
	if ((l->conv[0] == 'c' || l->conv[0] == 'C') && arg[0] == '\0')
		write(1, arg, 1);
	else
		write(1, arg, ft_strlen(arg));
	if (ft_strchr(l->flags, '-') && l->lenp > 0)
		print_lenf(l);
}

char	*print_prec(t_arg *l, char *arg)
{
	char	*tmp;

	tmp = NULL;
	if ((l->precision < ft_strlen(arg)) && l->conv[0] == 's' &&
		l->precision > -1)
		return (ft_strsub(arg, 0, l->precision));
	l->precision -= ft_strlen(arg);
	if (l->conv[0] != 's' && l->conv[0] != 'c' && l->conv[0] != 'C'
			&& l->conv[0] != '%' && l->precision > 0)
	{
		while (l->precision-- > 0)
			tmp = ft_strfjoin(tmp, "0");
		arg = ft_strfjoin(tmp, arg);
		l->precision = ft_strlen(arg);
	}
	return (arg);
}

void	print_lenf(t_arg *l)
{
	if ((ft_strchr(l->flags, '#') && l->point == 0) || l->conv[0] == 'p')
	{
		if (l->conv[0] == 'x' || l->conv[0] == 'X' || l->conv[0] == 'p')
			l->lenp -= 2;
		if (l->conv[0] == 'O' || l->conv[0] == 'o' || l->conv[0] == 'b')
			l->lenp--;
	}
	if (ft_strchr(l->flags, '+') || ft_strchr(l->flags, ' ') || l->neg == 1)
		l->lenp--;
	if (l->lenp > 0)
		l->str_len += l->lenp;
	if (ft_strchr(l->flags, '0') && !ft_strchr(l->flags, '-') && (l->point == 0
			|| l->conv[0] == 'c' || l->conv[0] == 's' || l->conv[0] == '%'))
		while (l->lenp-- > 0)
			write(1, "0", 1);
	else
		while (l->lenp-- > 0)
			write(1, " ", 1);
}
