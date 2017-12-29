/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:56:05 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:27:19 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_charcmp(unsigned char cmp, unsigned char src)
{
	int i;

	i = 0;
	if (src != cmp)
		i = cmp - src;
	return (i);
}
