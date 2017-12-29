/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:33:07 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:35:02 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		z = 0;
		while (big[i++] == little[z++])
		{
			if (little[z] == '\0')
				return (&((char*)big)[j]);
		}
		i = ++j;
	}
	return (NULL);
}
