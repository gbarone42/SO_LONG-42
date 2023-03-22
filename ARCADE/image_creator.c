/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:51:49 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/12 18:52:13 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_creator(t_images *images, void *mlx, int ww, int wh)
{
	int	wdt;

	wdt = 50;
	images->p = mlx_xpm_file_to_image(mlx, "./images/p.xpm", &wdt, &wdt);
	images->c = mlx_xpm_file_to_image(mlx, "./images/fuel.xpm", &wdt, &wdt);
	images->w = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wdt, &wdt);
	images->t = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &wdt, &wdt);
	images->e = mlx_xpm_file_to_image(mlx, "./images/e.xpm", &wdt, &wdt);
	images->f = mlx_xpm_file_to_image(mlx, "./images/win.xpm", &ww, &wh);
	images->g1 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->g2 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->g3 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->g4 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->l = mlx_xpm_file_to_image(mlx, "./images/l.xpm", &ww, &wh);
	door_anim(images, mlx, wdt);
}

void	door_anim(t_images *images, void *mlx, int wdt)
{
	images->e1 = mlx_xpm_file_to_image(mlx, "./images/plano.xpm", &wdt, &wdt);
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
	images->p1 = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->p2 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->p3 = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->p4 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->p5 = mlx_xpm_file_to_image(mlx, "./images/sellino.xpm", &wdt, &wdt);
	images->p6 = mlx_xpm_file_to_image(mlx, "./images/sborrolino.xpm", &wdt, &wdt);
	images->p7 = mlx_xpm_file_to_image(mlx, "./images/sellino2.xpm", &wdt, &wdt);
	images->black = mlx_xpm_file_to_image(mlx, "./images/b.xpm", &wdt, &wdt);
}
