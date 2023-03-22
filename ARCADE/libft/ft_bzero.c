/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:31:16 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/11 21:31:18 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		r[i] = '\0';
		i++;
		n--;
	}
}
/*
int main()
 {
         char s[10] = "ciaoo";
         char t[10] = "ciaoo";
         ft_bzero(s+ 2 , 4);
         bzero(t+ 2, 4);
         puts(s);
         puts(t);
}*/
