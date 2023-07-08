/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:53:20 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/20 17:53:21 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_mbcount(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_reverse( long int n, char *k)
{
	size_t		y;

	y = ft_mbcount(n);
	k[y] = '\0';
	if (n == 0)
		k[0] = '0';
	if (n < 0)
	{
		k[0] = '-';
		n *= -1;
	}
	y--;
	while (n != 0)
	{
		k[y] = (n % 10) + 48;
		n /= 10;
		y--;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	char		*k;
	size_t		f;
	long int	l;

	l = n;
	f = ft_mbcount(l);
	k = ft_calloc((f + 1), sizeof(char));
	if (!k)
		return (NULL);
	ft_reverse(l, k);
	return (k);
}
