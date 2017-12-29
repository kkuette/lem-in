/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:21:20 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:50 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsncpy(char *dst, const char *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[start])
		dst[i++] = src[start++];
	dst[i] = '\0';
	return (dst);
}
