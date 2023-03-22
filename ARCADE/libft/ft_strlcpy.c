/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:53:49 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/11 16:53:52 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	z;

	z = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (z);
}

/*
 int main () {
   const char src[50] = "abcdefghijkl";
   char dest[50] = "0123456789";
   printf("size = %ld\n%s\n", ft_strlcpy(dest, src, sizeof(char) * 10), dest);
} 
*/
/*
int	main()
{
	char src[] = "Woeeee";
	char dest[] = "ssss";
	printf("%ld", ft_strlcpy(dest, src, 9));
}
*/
