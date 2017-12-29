/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:31:41 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 19:28:51 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*l;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = f(lst);
	l = new;
	while (lst->next)
	{
		if ((new->next = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (l);
}
