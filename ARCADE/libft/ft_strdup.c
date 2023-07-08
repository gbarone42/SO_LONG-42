/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:47:17 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/12 21:47:54 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*y;
	size_t	f;

	f = 0;
	y = malloc(ft_strlen((char *)s) + 1);
	if (!y)
		return (NULL);
	while (s[f] != '\0')
	{
		y[f] = s[f];
		f++;
	}
	y[f] = '\0';
	return (y);
}
/*
int main()
{
	const char s[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strdup(s));
}
*/
