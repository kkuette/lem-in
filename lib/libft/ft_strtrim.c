/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:29:23 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:35:21 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (new = "\0");
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
		len--;
	len = len - i + 1;
	if ((new = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	new = ft_strsncpy(new, s, i, len);
	return (new);
}
