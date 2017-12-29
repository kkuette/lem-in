/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:50:18 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/12 05:56:48 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		len1;
	int		len2;
	size_t	lentot;
	size_t	i;

	i = 0;
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	lentot = (((size_t)len1) + ((size_t)len2) + 1);
	if ((new = ft_memalloc(lentot)) == NULL)
		return (NULL);
	while (i < ((size_t)len1))
	{
		new[i] = s1[i];
		i++;
	}
	len1 = ((int)i);
	i = 0;
	while (i < ((size_t)len2))
		new[len1++] = s2[i++];
	new[len1++] = '\0';
	return (new);
}
