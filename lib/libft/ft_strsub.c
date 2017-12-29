/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:32:34 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:35:16 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if ((str = ft_memalloc(len + 1)) == NULL)
		return (str);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
