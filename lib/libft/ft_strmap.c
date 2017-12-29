/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:49:04 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:33:35 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(((char*)s)[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
