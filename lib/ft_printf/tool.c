/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:12:45 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:12:09 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uintmtoa_base(uintmax_t n, int base, char *conv)
{
	char		*ret;
	int			i;

	i = ft_uintmlen_base(n, base);
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

int		ft_uintlen_base(unsigned int n, int base)
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

char	*ft_imtoa(intmax_t n)
{
	char		*nbr;
	int			i;
	intmax_t	ns;

	i = 0;
	ns = n;
	if (!(nbr = (char*)malloc(sizeof(char) * ft_nbrlen(n) + 2)))
		return (NULL);
	if (ns == -9223372036854775807 - 1)
		nbr = ft_strdup("8085774586302733229-");
	if (ns < 0)
		n *= -1;
	while (n > 0 && ns != -9223372036854775807 - 1)
	{
		nbr[i++] = n % 10 + '0';
		n /= 10;
	}
	if (ns == 0)
		nbr[i] = '0';
	if (ns < 0 && ns != -9223372036854775807 - 1)
		nbr[i++] = '-';
	ft_strrev(nbr);
	return (nbr);
}

char	*ft_ctoa(char c)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*ft_uctoa(unsigned char n, int base, char *conv)
{
	char			*ret;
	int				i;

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
