/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:56:41 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:32:27 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*cpy;

	len = ft_strlen((char*)str);
	if (!str || (cpy = (char*)malloc(1 + len * sizeof(char))) == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, str);
	return (cpy);
}
