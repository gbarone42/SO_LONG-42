/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:14:01 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 19:38:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_destroyer(t_images *i, void *m)
{
	mlx_destroy_image(m, i->uscita);
	mlx_destroy_image(m, i->airplane);
	mlx_destroy_image(m, i->e2);
	mlx_destroy_image(m, i->e3);
	mlx_destroy_image(m, i->e4);
	mlx_destroy_image(m, i->e5);
	mlx_destroy_image(m, i->e6);
	mlx_destroy_image(m, i->e7);
	mlx_destroy_image(m, i->e8);
	mlx_destroy_image(m, i->e9);
	mlx_destroy_image(m, i->e10);
	mlx_destroy_image(m, i->e11);
	mlx_destroy_image(m, i->e12);
	mlx_destroy_image(m, i->e13);
	mlx_destroy_image(m, i->e14);
}

void	image_destroyer(t_images *i, void *m)
{
	mlx_destroy_image(m, i->black);
	mlx_destroy_image(m, i->carburante);
	mlx_destroy_image(m, i->win_game_banner);
	mlx_destroy_image(m, i->guardia1);
	mlx_destroy_image(m, i->guardia2);
	mlx_destroy_image(m, i->guardia3);
	mlx_destroy_image(m, i->guardia4);
	mlx_destroy_image(m, i->endgame_lost);
	mlx_destroy_image(m, i->sb___one);
	mlx_destroy_image(m, i->p);
	mlx_destroy_image(m, i->sb2);
	mlx_destroy_image(m, i->sb3);
	mlx_destroy_image(m, i->sb4);
	mlx_destroy_image(m, i->sb5);
	mlx_destroy_image(m, i->sb6);
	mlx_destroy_image(m, i->sb7);
	mlx_destroy_image(m, i->t);
	mlx_destroy_image(m, i->wall);
	door_destroyer(i, m);
}

void	map_destroyer(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

int	sfree(t_game *game)
{
	int	i;

	i = 0;
	game->f = 1;
	free(game->pp);
	while (i < game->g_n)
	{
		free(game->ghosts[i]);
		i++;
	}
	map_destroyer(game->map);
	free(game->ghosts);
	image_destroyer(game->images, game->mlx);
	free(game->images);
	mlx_destroy_window(game->mlx, game->window);
	return (0);
}
