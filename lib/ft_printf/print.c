/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:05:55 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 17:54:37 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_print(t_arg *l, va_list args)
{
	int		ret;

	ret = 0;
	if (l->conv[0] == 's' || l->conv[0] == 'c' || l->conv[0] == '%'
			|| l->conv[0] == 'C' || l->conv[0] == 'S')
		ret = select_print_c(l, args);
	else if (l->conv[0] == 'd' || l->conv[0] == 'i' || l->conv[0] == 'D')
		ret = print_nbr(l, args);
	else if (l->conv[0] == 'x' || l->conv[0] == 'X' || l->conv[0] == 'p')
		ret = print_hex(l, args);
	else if (l->conv[0] == 'o' || l->conv[0] == 'O')
		ret = print_octal(l, args);
	else if (l->conv[0] == 'b')
		ret = print_binary(l, args);
	else if (l->conv[0] == 'u' || l->conv[0] == 'U')
		ret = print_unbr(l, args);
	return (ret);
}
