/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 23:03:24 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghosts_init(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->g_n)
	{
		ghost_init(game, game->ghosts[i]);
		i++;
	}
}

void	ghost_init(t_game *game, t_vector *ghost)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
			{
				game->map[y][x] = '0';
				ghost->x = x;
				ghost->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

t_vector	**ghost_creator(t_game *game)
{
	t_vector	**temp;
	int			i;

	i = 0;
	temp = malloc(sizeof(t_vector *) * game->g_n);
	while (i < game->g_n)
	{
		temp[i] = malloc(sizeof(t_vector));
		temp[i]->x = 0;
		temp[i]->y = 0;
		i++;
	}
	return (temp);
}


