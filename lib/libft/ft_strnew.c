/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:45:56 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:23 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 1;
	str = ft_memalloc(size + i);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
