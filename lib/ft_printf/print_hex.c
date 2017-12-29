/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:46:18 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:12:36 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_hex(t_arg *l, va_list args)
{
	int		ret;
	char	*v;

	ret = 0;
	if (l->lenmod[0] == '\0' && l->conv[0] != 'p')
		v = choose_utype(l, args, 16);
	else
		v = choose_utype(l, args, 16);
	if (l->point == 1 && l->precision == 0 && v[0] == '0' && v[1] == '\0')
		v[0] = '\0';
	choose_prec(l, v);
	return (ret);
}

int		print_octal(t_arg *l, va_list args)
{
	int		ret;
	char	*v;

	ret = 0;
	if (l->lenmod[0] == '\0' && l->conv[0] != 'O')
		v = choose_utype(l, args, 8);
	else
		v = choose_utype(l, args, 8);
	if (v[0] == '0' && v[1] == '\0' && !ft_strchr(l->flags, '#') &&
			l->point == 1)
		v[0] = '\0';
	choose_prec(l, v);
	return (ret);
}

int		print_binary(t_arg *l, va_list args)
{
	int		ret;
	char	*v;

	if (l->lenmod[0] == '\0')
		v = choose_utype(l, args, 2);
	else
		v = choose_utype(l, args, 2);
	if (l->point == 1 && l->precision == 0 && v[0] == '0' && v[1] == '\0')
		v[0] = '\0';
	ret = 0;
	choose_prec(l, v);
	return (ret);
}

char	*ft_uinttoa(unsigned int n, int base, char *conv)
{
	char	*ret;
	int		i;

	i = ft_uintlen_base(n, base);
	if (!(ret = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		i--;
		if (n % base > 9 && (conv[0] == 'x' || conv[0] == 'p') && base == 16)
			ret[i] = n % base - 10 + 97;
		else if (n % base > 9 && conv[0] == 'X' && base == 16)
			ret[i] = n % base - 10 + 65;
		else
			ret[i] = n % base + '0';
		n /= base;
	}
	return (ret);
}

int		ft_uintmlen_base(uintmax_t n, int base)
{
	int ret;

	ret = 0;
	while (n != 0)
	{
		n /= base;
		ret++;
	}
	return (ret);
}
