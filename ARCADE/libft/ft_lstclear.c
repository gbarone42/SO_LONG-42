/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:09:18 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/05 19:11:56 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*k;

	if (lst == 0)
		return ;
	while (*lst != 0)
	{
		k = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = k;
	}
	*lst = NULL;
}
