/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:48:37 by gbarone          #+#    #+#              */
/*   Updated: 2022/10/21 17:50:09 by gbarone         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int nb, int fd, int *count)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		n = (unsigned int)(nb * -1);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, count);
	ft_putchar_fd((char)(n % 10 + 48), fd, count);
}
