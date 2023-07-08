/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:44:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 00:34:14 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_counter(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				n++;
			i++;
		}
		j++;
	}
	return (n);
}

int	invalid_char_check(char **map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			c = map[j][i];
			if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E'
				&& c != 'G' && c != '\n') //The valid characters are '1', '0', 'C', 'P', 'E', 'G', and newline characters.
				return (1); //error
			i++;
		}
		j++;
	}
	return (0);
}

int	char_checker(char **map) //contain at least one C, maximum one P and one E
{
	if (char_counter(map, 'P') != 1)
		return (1);
	if (char_counter(map, 'E') != 1)
		return (1);
	if (char_counter(map, 'C') == 0)
		return (1);
	return (0);
}

t_vector	char_finder(char **map, char c)
{
	int			i;
	int			j;
	t_vector	e;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				e.x = i;
				e.y = j;
			}
			i++;
		}
		j++;
	}
	return (e);
}
