/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:51:38 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:29:51 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tmp;

	tmp = ft_strsub(src, 0, len);
	dest = ft_memcpy(dest, tmp, len);
	return (dest);
}
