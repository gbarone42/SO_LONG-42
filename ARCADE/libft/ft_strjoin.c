/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:13:26 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/20 17:13:30 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*p;
	int				l;
	int				j;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(l);
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (s1[i] != 0)
		p[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		p[j++] = s2[i++];
	p[j] = 0;
	return (p);
}

/*
char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*l;
	unsigned int	p;
	unsigned int	k;

	p = 0;
	k = 0;
	l = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!l)
		return (NULL);
	while (s1[p] != '\0')
	{
		l[p] = s1[p];
		p++;
	}
	while (s2[k] != '\0')
	{
		l[p + k] = s2[k];
		k++;
	}
	l[p + k] = '\0';
	return (l);
}*/
/*
 int main()
{
	const char *s1 = "abcd";
	const char *s2 = "efgh";
	printf("%s\n", ft_strjoin(s1, s2));
} */
