/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:10:20 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/26 19:10:22 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libft.h"

static int	wordcount(const char *str, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*stralloc(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof (char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	int		l;
	size_t	j;
	char	**split;

	split = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	i = 0;
	l = -1;
	j = 0;
	if (!split || !s)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && l < 0)
			l = i;
		else if ((s[i] == c || s[i] == '\0') && l >= 0)
		{
			split[j++] = stralloc(s, l, i);
			l = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
int	ft_countdel( const char *str, char del)
{
	int	i;
	int	countdel;

	i = 0;
	countdel = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == del)
			countdel++;
	}
	return (countdel + 1);
}

char	*ft_newsub(char **str, char c)
{
	int		i;
	char	*unptr;

	i = 0;
	while (str[0][i] != '\0' && str[0][i] != c)
		i++;
	unptr = malloc(sizeof(char) * (i + 1));
	if ( unptr == NULL )
		return ( NULL );
	ft_strlcpy(unptr, str[0], --i);
		i++;
	str[0] = str[0] + 1 + i;
	printf("%s\n" , unptr);
	return (unptr);
}

char	**ft_split(char const *s, char c)

{
	char	**p;
	int		i;
	int		countdel;

	countdel = ft_countdel(s, c);
	i = 0;
	p = (char **)malloc(sizeof (char *) * (countdel + 1));
	if ( p == NULL )
		return ( NULL );
	while (*s != '\0')
	{
		p[i] = ft_newsub((char **)&s, c);
		i++;
		
	}
	p[i] = 0;
	return (p);
}

int	main(void)
{	char str[]= "hry cciao";
	char **q;
	q = ft_split(str, ' ');
	int i;
	i = 0;
	while(q)
	{
		printf("%s\n", q[i]);
		i++;
	}
}
*/
