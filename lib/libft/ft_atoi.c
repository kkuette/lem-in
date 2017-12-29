/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:55:50 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:27:02 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t	ft_atoi(const char *nptr)
{
	intmax_t	nb;
	int			i;
	int			neg;

	neg = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= 0 && nptr[i] <= 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if (ft_isdigit(nptr[i]) == 0)
			return (nb * neg);
		nb = nb * 10 + nptr[i++] - '0';
	}
	return (nb * neg);
}
