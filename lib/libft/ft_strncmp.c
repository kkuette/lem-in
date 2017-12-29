/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:07:22 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:03 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while ((s2[i] != '\0' || s1[i] != '\0') && diff == 0 && i < n)
	{
		diff = ft_charcmp((unsigned char)s1[i], (unsigned char)s2[i]);
		i++;
	}
	return (diff);
}
