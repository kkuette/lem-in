/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 12:55:01 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:54:21 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_print_c(t_arg *l, va_list args)
{
	int		ret;

	ret = 0;
	if (l->conv[0] == '%')
		print_p(l);
	if (l->conv[0] == 'c' && l->lenmod[0] == '\0')
		print_c(l, args);
	if (l->conv[0] == 's' && l->lenmod[0] == '\0')
		print_s(l, args);
	if (l->conv[0] == 'S' || (l->conv[0] == 's' && !ft_strcmp(l->lenmod, "l")))
		print_ws(l, args);
	if (l->conv[0] == 'C' || (l->conv[0] == 'c' && !ft_strcmp(l->lenmod, "l")))
		print_wc(l, args);
	return (ret);
}

int		print_p(t_arg *l)
{
	int		ret;

	ret = 0;
	choose_prec(l, "%");
	return (ret);
}

int		print_c(t_arg *l, va_list args)
{
	int		ret;
	char	c;

	c = (char)va_arg(args, int);
	ret = 0;
	if (c == '\0')
		choose_prec(l, "\0");
	else
		choose_prec(l, ft_ctoa(c));
	return (ret);
}

int		print_s(t_arg *l, va_list args)
{
	int		ret;
	char	*c;

	c = va_arg(args, char*);
	ret = 0;
	if (c == NULL)
		c = ft_strdup("(null)");
	choose_prec(l, c);
	return (ret);
}
