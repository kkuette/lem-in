/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:49:40 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:33:16 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	lentot;
	size_t	lend;

	lend = ft_strlen(dest);
	lentot = lend + ft_strlen((char*)src);
	if (!(dest = ft_memchr(dest, '\0', len)))
		return (len + ft_strlen((char*)src));
	while (*src && lend < len - 1)
	{
		*dest++ = *src++;
		lend++;
	}
	*dest = '\0';
	return (lentot);
}
