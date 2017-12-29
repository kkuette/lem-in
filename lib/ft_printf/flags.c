/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:20 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:03:14 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg		*search_flags(t_arg *l, const char *fmt)
{
	while (fmt[l->len_read] == ' ' || fmt[l->len_read] == '0' ||
			fmt[l->len_read] == '+' || fmt[l->len_read] == '#' ||
			fmt[l->len_read] == '-')
	{
		if (fmt[l->len_read] == '#' && !ft_strchr(l->flags, '#'))
			l->flags = ft_strjoin(l->flags, "#");
		if (fmt[l->len_read] == '0' && !ft_strchr(l->flags, '0'))
			l->flags = ft_strjoin(l->flags, "0");
		if (fmt[l->len_read] == '-' && !ft_strchr(l->flags, '-'))
			l->flags = ft_strjoin(l->flags, "-");
		if (fmt[l->len_read] == '+' && !ft_strchr(l->flags, '+'))
			l->flags = ft_strjoin(l->flags, "+");
		if (fmt[l->len_read] == ' ' && !ft_strchr(l->flags, ' '))
			l->flags = ft_strjoin(l->flags, " ");
		l->len_read++;
	}
	return (l);
}

void		apply_flags(t_arg *l, char *arg)
{
	if (ft_strchr(l->flags, '#') || l->conv[0] == 'p')
	{
		if (((arg[0] != '\0' && ft_strcmp(arg, "0")) || l->conv[0] == 'p') &&
			(l->conv[0] == 'X' || l->conv[0] == 'x' || l->conv[0] == 'p'))
		{
			if ((l->conv[0] == 'x') || l->conv[0] == 'p')
				write(1, "0x", 2);
			if (l->conv[0] == 'X')
				write(1, "0X", 2);
			l->str_len += 2;
		}
		if ((l->conv[0] == 'o' || l->conv[0] == 'O' || l->conv[0] == 'b')
			&& ft_strcmp(arg, "0") && l->precision != ft_strlen(arg))
		{
			write(1, "0", 1);
			l->str_len++;
		}
	}
	if (l->neg == 1 && !ft_strchr(arg, '-'))
	{
		l->str_len++;
		write(1, "-", 1);
	}
}

void		apply_flags_s(t_arg *l, char *arg)
{
	if (ft_strchr(l->flags, '+') && l->neg == 0 &&
			l->conv[0] != 'u' && l->conv[0] != 'U' && l->conv[0] != 'c'
			&& l->conv[0] != 'C' && l->conv[0] != 'o' && l->conv[0] != 'O'
			&& l->conv[0] != 's' && l->conv[0] != 'S' && l->conv[0] != 'p'
			&& l->conv[0] != 'x' && l->conv[0] != 'X')
	{
		l->str_len++;
		write(1, "+", 1);
	}
	if (ft_strchr(l->flags, ' ') && l->neg == 0 && l->conv[0] != '%' &&
			l->conv[0] != 'u' && l->conv[0] != 'U' && l->conv[0] != 'c' &&
			l->conv[0] != 'C' && l->conv[0] != 'o' && l->conv[0] != 'O' &&
			!ft_strchr(l->flags, '+') && l->conv[0] != 'p'
			&& l->conv[0] != 's' && l->conv[0] != 'S'
			&& l->conv[0] != 'x' && l->conv[0] != 'X')
	{
		l->str_len++;
		write(1, " ", 1);
	}
	apply_flags(l, arg);
}
