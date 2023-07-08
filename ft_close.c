/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:03 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 19:38:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_death(t_game *game)
{
	int	i;

	i = 0;
	game->dead = 0;
	while (i < game->g_n)
	{
		if (game->pp->x == game->ghosts[i]->x)
			if (game->pp->y == game->ghosts[i]->y)
				game->dead = 1;
		i++;
	}
	if (game->dead)
		ft_close(game);
}

void	ft_close(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	game->f = 1;
	if (!game->dead)
		mlx_put_image_to_window(game->mlx, game->window, game->images->win_game_banner, 0, 0);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->images->endgame_lost, 0, 0);
}
