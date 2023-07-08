/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:50:16 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 19:38:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_updater_2(t_game *game, int x, int y, int u)
{
	if (game->frame > u * 4 && game->frame <= u * 5)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e5, x, y);
	if (game->frame > u * 5 && game->frame <= u * 6)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e6, x, y);
	if (game->frame > u * 6 && game->frame <= u * 7)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e7, x, y);
	if (game->frame > u * 7 && game->frame <= u * 8)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e8, x, y);
	if (game->frame > u * 8 && game->frame <= u * 9)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e9, x, y);
	if (game->frame > u * 9 && game->frame <= u * 10)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e10, x, y);
	if (game->frame > u * 10 && game->frame <= u * 11)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e11, x, y);
	if (game->frame > u * 11 && game->frame <= u * 12)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e12, x, y);
	if (game->frame > u * 12 && game->frame <= u * 13)
		mlx_put_image_to_window(game->mlx, game->window, game->images->e13, x, y);
	if (game->frame > u * 13)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->images->e14, x, y);
		game->coins = -1;
	}
}

void	door_updater(t_game *game, int x, int y, t_images *images)
{
	static int	start;
	int			u;

	u = game->maxf / 14;
	if (game->coins > 0)
		mlx_put_image_to_window(game->mlx, game->window, images->uscita, x, y);
	if (game->coins == 0 && game->frame == 1)
		start = 1;
	if (game->coins == 0 && start == 1)
	{
		if (game->frame <= u)
			mlx_put_image_to_window(game->mlx, game->window, images->airplane, x, y);
		if (game->frame > u && game->frame <= u * 2)
			mlx_put_image_to_window(game->mlx, game->window, images->e2, x, y);
		if (game->frame > u * 2 && game->frame <= u * 3)
			mlx_put_image_to_window(game->mlx, game->window, images->e3, x, y);
		if (game->frame > u * 3 && game->frame <= u * 4)
			mlx_put_image_to_window(game->mlx, game->window, images->e4, x, y);
		if (game->frame > u * 4)
			door_updater_2(game, x, y, u);
	}
	if (game->coins == -1)
		mlx_put_image_to_window(game->mlx, game->window, images->e14, x, y);
}
/*
void	moves_counter(t_game *game, void *b)
{
	char	*m;

	m = ft_itoa_base("0123456789", game->moves);
	if (game->moved == 1)
		mlx_put_image_to_window(game->mlx, game->win, b, game->w_w - 50, 0);
	mlx_string_put(game->mlx, game->win, game->w_w - 50, 25, 255000000, m);
	game->moved = 0;
	free(m);
}
*/

size_t	ft_count(long int i)
{
	size_t	count;

	count = 0;
	if (i < 0)
	{
		i = i * -1;
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_logic(char *s, size_t count, size_t i, int n)
{
	while (count-- > i)
	{
		if (n < 0)
		{
			s[count] = '0' + (n % 10 * (-1));
			n = n / 10;
		}
		else
		{
			s[count] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	count;

	count = ft_count(n);
	s = (char *)malloc((count + 1));
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		i = 1;
	}
	else
		i = 0;
	ft_logic(s, count, i, n);
	return (s);
}

void	moves_counter(t_game *game)
{
	char	*move;

	move = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 20, 15, 0xffffffff, "Moves :");
	mlx_string_put(game->mlx, game->window, 80, 15, 0xffffffff, move);
	free(move);
}

void	image_updater(char c, int x, int y, t_game *game)
{
	void	*p;

	p = game->mlx;
	x = x * 50;
	y = y * 50;
	if (!(x / 50 == game->pp->x && y / 50 == game->pp->y))
	{
		if (c == '0')
			mlx_put_image_to_window(p, game->window, game->images->t, x, y);
		if (c == '1')
			mlx_put_image_to_window(p, game->window, game->images->wall, x, y);
		if (c == 'C')
			mlx_put_image_to_window(p, game->window, game->images->carburante, x, y);
		if (c == 'E')
			door_updater(game, x, y, game->images);
	}
}

int	updater(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (game->f)
		return (0);
	if (game->map[game->pp->y][game->pp->x] == 'C')
	{
		game->map[game->pp->y][game->pp->x] = '0';
		game->coins--;
	}
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			image_updater(game->map[y][x], x, y, game);
			x++;
		}
		y++;
	}
	render(game);
	return (0);
}
