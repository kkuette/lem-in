/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:29:58 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:28:25 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = *alst;
		del(tmp->content, tmp->content_size);
		free(*alst);
		*alst = tmp->next;
	}
}
