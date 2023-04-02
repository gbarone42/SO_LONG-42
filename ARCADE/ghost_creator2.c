/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_creator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:25:06 by gbarone           #+#    #+#             */
/*   Updated: 2023/04/02 16:25:08 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghost_mover(t_game *game, t_vector *ghost, int i)
{
	static int	*dir;

	if (!dir)
		dir = malloc(sizeof(int) * game->g_n);
	if (dir[i] != 1 && dir[i] != -1)
		dir[i] = -1;
	if (game->map[ghost->y + dir[i]][ghost->x] == '0')
	{
		if (dir[i] == -1)
			ghost->y--;
		else
			ghost->y++;
	}
	else if (game->map[ghost->y - dir[i]][ghost->x] == '0')
	{
		dir[i] = -dir[i];
		ghost_mover(game, ghost, i);
	}
}


void	ghost_manager(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->g_n)
	{
		if (game->frame == game->maxf)
			ghost_mover(game, game->ghosts[i], i);
		i++;
	}
	i = 0;
	while (i < game->g_n)
	{
		ghost_render(game, game->ghosts[i]);
		i++;
	}
}

void	ghost_render(t_game *game, t_vector *ghost)
{
	int	x;
	int	y;
	int	u;

	u = game->maxf / 4;
	x = ghost->x * 50;
	y = ghost->y * 50;
	if (game->frame <= u)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g1, x, y);
	if (game->frame > u && game->frame <= u * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g2, x, y);
	if (game->frame > u * 2 && game->frame <= u * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g3, x, y);
	if (game->frame > u * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g4, x, y);
}
