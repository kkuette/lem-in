/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:33:30 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:34:56 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**splited;
	int		i;
	int		co;

	co = 0;
	i = 0;
	if ((splited = (char **)malloc(sizeof(char *) *
					(ft_cword_bc((char*)s, c) + 1))) == NULL || s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			splited[co] = ft_strsub(s, i, ft_strlen_bc((char*)s, c, i));
			i = i + ft_strlen_bc((char*)s, c, i);
			co++;
		}
		else
			i++;
	}
	splited[co] = NULL;
	return (splited);
}
