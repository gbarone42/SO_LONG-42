/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:00:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/20 19:45:23 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->map_lines = 0;
	game->g_n = 0;
	game->coins = 0;
	game->moves = 0;
	game->moved = 1;
	game->frame = 1;
	game->f = 0;
}

int	check_init(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (0);
	if (ac > 2)
		ft_printf("\033[0;31mToo many arguments (It should be only two).\n\033[0;37m");
	if (ac < 2)
		ft_printf("\033[0;31mThe Map file is missing.\n\033[0;37m");
	if (maps_check(av[1]) != 0)
	{
		ft_printf("\033[0;31mMammamia! Waju' eddaje insert a valid map!\n\033[0;37m");
		return (0);
	}
	game_init(game);
	game->map = map_generator(av[1], game);
	game->mlx = mlx_init();
	game->images = malloc(sizeof(t_images));
	game->pp = malloc (sizeof(t_vector));
	game->pp->x = 0;
	game->pp->y = 0;
	game->ghosts = ghost_creator(game);
	ghosts_init(game);
	image_creator(game->images, game->mlx, game->w_w, game->w_h);
	game->win = mlx_new_window(game->mlx, game->w_w, game->w_h, "so_long");
	player_init(game);
	return (1);
}
