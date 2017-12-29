/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:53:40 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:28:12 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char			*nbr;
	int				i;
	int				ns;

	i = 0;
	ns = n;
	if ((nbr = ft_memalloc(sizeof(char) * ft_nbrlen(n) + 2)) == NULL)
		return (NULL);
	if (ns == -2147483648)
		nbr = ft_strdup("8463847412-");
	if (ns < 0)
		n = n * -1;
	while (n > 0)
	{
		nbr[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (ns == 0)
		nbr[i] = '0';
	if (ns < 0 && ns != -2147483648)
		nbr[i++] = '-';
	ft_strrev(nbr);
	return (nbr);
}
