/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:39 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 00:34:12 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{	
	t_game	game;
	int		control;

	control = check_init(ac, av, &game);
	if (!control)
		return (0);
	mlx_key_hook(game.win, input_manager, &game);
	mlx_loop_hook(game.mlx, updater, &game);
	mlx_hook(game.win, 17, 0, sfree, &game);
	mlx_loop(game.mlx);
}
