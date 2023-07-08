/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:51:49 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/04 02:43:51 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_creator(t_images *images, void *mlx, int ww, int wh)
{
	int	wdt;

	wdt = 50;
	images->p = mlx_xpm_file_to_image(mlx, "./images/p.xpm", &wdt, &wdt);
	images->carburante = mlx_xpm_file_to_image(mlx, "./images/fuel.xpm", &wdt, &wdt);
	images->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wdt, &wdt);
	images->t = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &wdt, &wdt);
	images->uscita = mlx_xpm_file_to_image(mlx, "./images/e.xpm", &wdt, &wdt);
	images->win_game_banner = mlx_xpm_file_to_image(mlx, "./images/win.xpm", &ww, &wh);
	images->airplane = mlx_xpm_file_to_image(mlx, "./images/plano.xpm", &wdt, &wdt);
	images->e2 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e3 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e4 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e5 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e6 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e7 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e8 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e9 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e10 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e11 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e12 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e13 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &wdt, &wdt);
	images->e14 = mlx_xpm_file_to_image(mlx, "./images/plano.xpm", &wdt, &wdt);	
	images->endgame_lost = mlx_xpm_file_to_image(mlx, "./images/l.xpm", &ww, &wh);		
	door_anim(images, mlx, wdt);
}

void	door_anim(t_images *images, void *mlx, int wdt)
{		
	images->guardia1 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->guardia2 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->guardia3 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->guardia4 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->sb___one = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->sb2 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->sb3 = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->sb4 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->sb5 = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->sb6 = mlx_xpm_file_to_image(mlx, "./images/sborrolino.xpm", &wdt, &wdt);
	images->sb7 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->black = mlx_xpm_file_to_image(mlx, "./images/b.xpm", &wdt, &wdt);
}
