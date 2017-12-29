/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:01:06 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:31:54 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int diff;

	diff = 0;
	i = 0;
	while (diff == 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		diff = ft_charcmp((unsigned char)s1[i], (unsigned char)s2[i]);
		i++;
	}
	return (diff);
}
