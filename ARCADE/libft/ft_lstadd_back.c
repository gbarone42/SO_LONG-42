/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:50:24 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/25 13:50:26 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*k;

	if (! *lst)
	{
		*lst = new;
		return ;
	}
	k = ft_lstlast(*lst);
	k->next = new;
}
