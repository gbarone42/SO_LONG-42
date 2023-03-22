/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:06:08 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/14 18:06:14 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		c = (unsigned int)n * -1;
	}
	else
		c = (unsigned int)n;
	if (c >= 10)
		ft_putnbr_fd(c / 10, fd);
	ft_putchar_fd((unsigned int )(c % 10 + 48), fd);
}
/*
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}*/
