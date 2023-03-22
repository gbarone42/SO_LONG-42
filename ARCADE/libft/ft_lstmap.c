/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:09:37 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/05 19:19:30 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*y;
	t_list	*k;

	if (lst == NULL)
		return (NULL);
	y = NULL;
	while (lst != 0)
	{
		k = ft_lstnew((*f)(lst->content));
		if (k == NULL)
			ft_lstclear(&k, (*del));
		else
			ft_lstadd_back(&y, k);
		lst = lst-> next;
	}
	return (y);
}
