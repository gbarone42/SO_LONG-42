/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:48:37 by gbarone          #+#    #+#              */
/*   Updated: 2022/10/21 17:50:09 by gbarone         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru_fd(unsigned int nb, int fd, int *count)
{
	long long unsigned	n;

	n = (long long unsigned)nb;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, count);
	ft_putchar_fd((char)(n % 10 + 48), fd, count);
}
