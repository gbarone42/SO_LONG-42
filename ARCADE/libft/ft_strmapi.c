/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:19:31 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/20 17:19:32 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	k;
	char	*y;

	k = 0;
	if (!s && !f)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	y = ft_strdup(s);
	if (!y)
		return (NULL);
	while (s[k])
	{
		y[k] = (*f)(k, s[k]);
		k++;
	}
	return (y);
}
/*
int main()
{
	char *y = "ciao";
	int   k = 12;	 
	char  *f = "bene";
	printf("%s\n", ft_strmapi(y,(k, f)));
}*/
