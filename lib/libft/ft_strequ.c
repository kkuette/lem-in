/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:51:20 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:32:39 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		cmp;

	cmp = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		cmp = ft_charcmp(s1[i], s2[i]);
		if (cmp != 0)
			return (0);
		i++;
	}
	return (1);
}
