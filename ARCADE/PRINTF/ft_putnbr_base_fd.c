/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:44:23 by gbarone          #+#    #+#              */
/*   Updated: 2022/10/21 17:44:39 by gbarone         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_putnbr_base_fd(uintptr_t nbr, int fd, int *count)
{	
	if (nbr >= 16)
	{
		ft_putnbr_base_fd(nbr / 16, fd, count);
		ft_putnbr_base_fd(nbr % 16, fd, count);
	}
	else
		ft_putchar_fd("0123456789abcdef"[nbr], fd, count);
}
