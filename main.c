/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:39 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 19:49:22 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{	
	t_game	game;
	//int		control;

	//control = check_init(ac, av, &game);
	if (control_init(ac, av, &game) == 0)
		return (1);
	mlx_key_hook(game.window, input_manager, &game);
	mlx_loop_hook(game.mlx, updater, &game);
	mlx_hook(game.window, 17, 0, sfree, &game);
	mlx_loop(game.mlx);
}
