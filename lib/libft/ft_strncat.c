/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:47:19 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:33:46 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	i = 0;
	lens = ft_strlen((char*)src);
	lend = ft_strlen(dest);
	while (i < n && i < lens)
		dest[lend++] = src[i++];
	dest[lend++] = '\0';
	return (dest);
}
