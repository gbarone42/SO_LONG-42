/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:41:51 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/14 16:41:58 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	y;
	int	i;

	i = 0;
	y = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	while (ft_strchr(set, s1[y]) != NULL)
		y--;
	return (ft_substr (s1, i, y - i + 1));
}
/*
int	main()
{
	const char s1[] = "abcdefg";
	const char set[] = "af";
	printf("%s\n", ft_strtrim(s1, set));
}
*/
