/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:47:47 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:33:41 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if ((new = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(i, ((char*)s)[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
