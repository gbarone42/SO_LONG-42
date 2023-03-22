/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:13:45 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/11 17:13:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		j;
	char		*i;
	const char	*k;

	j = 0;
	i = dst;
	k = src;
	if (!dst && !src)
		return (NULL);
	while (j < n)
	{
		i[j] = k[j];
		j++;
	}
	return (dst);
}
/*
 int main () 
{
   const char src[50] = "abcdefghijk";
   char dest[50] = "0123456789";
   printf("Before = %s\n", dest);
   ft_memcpy(&dest, &src, sizeof(char) * 9);
   printf("After = %s\n", dest);
} 
*/
