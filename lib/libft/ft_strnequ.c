/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:46:29 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:18 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	cmp = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		cmp = ft_charcmp(s1[i], s2[i]);
		if (cmp != 0)
			return (0);
		i++;
	}
	if (cmp == 0)
		return (1);
	return (0);
}
