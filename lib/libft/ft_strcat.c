/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:52:32 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:31:28 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int lend;
	int lens;

	i = 0;
	lend = ft_strlen(dest);
	lens = ft_strlen((char*)src);
	while (i < lens)
		dest[lend++] = src[i++];
	dest[lend++] = '\0';
	return (dest);
}
