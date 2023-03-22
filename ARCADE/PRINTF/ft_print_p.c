/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:58:07 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/14 14:58:18 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(uintptr_t nbr, int fd, int *count)
{
	if (!nbr)
		ft_putstr_fd("(nil)", fd, count);
	else
	{
		ft_putstr_fd("0x", fd, count);
		ft_putnbr_base_fd(nbr, fd, count);
	}
}
