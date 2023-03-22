/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:25:56 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/05 20:26:00 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		j;

	s1 = (char *)dst;
	s2 = (const char *)src;
	j = 0;
	if (dst > src)
	{
		while (j < n)
		{
			s1[n - j - 1] = s2[n - j - 1];
			j++;
		}
	}
	else
	{
		ft_memcpy(s1, s2, n);
	}
	return (dst);
}
/*
int main () {
   const char src[50] = "abcdefghijk";
   char dest[50] = "0123456789";
   printf("Before memmove dest = %s\n", dest);
   ft_memmove(&dest, &src, sizeof(char) * 2);
   printf("After memmove dest = %s\n", dest);
} */
