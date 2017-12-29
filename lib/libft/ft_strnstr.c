/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:43:40 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:28 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		z = 0;
		while (big[i++] == little[z++])
		{
			if (little[z] == '\0')
				return (&((char*)big)[j]);
			if (i == len)
				return (NULL);
		}
		i = ++j;
	}
	return (NULL);
}
