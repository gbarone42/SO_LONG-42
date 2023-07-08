/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:48 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 19:38:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
//# include "mlx_int.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_images
{
	void	*p;
	void	*carburante;
	void	*wall;
	void	*t;
	void	*uscita;
	void	*win_game_banner;
	void	*airplane;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*e5;
	void	*e6;
	void	*e7;
	void	*e8;
	void	*e9;
	void	*e10;
	void	*e11;
	void	*e12;
	void	*e13;
	void	*e14;
	void	*guardia4;
	void	*guardia3;
	void	*guardia2;
	void	*guardia1;
	void	*endgame_lost;
	void	*sb___one;
	void	*sb2;
	void	*sb3;
	void	*sb4;
	void	*sb5;
	void	*sb6;
	void	*sb7;
	void	*black;
}	t_images;

typedef struct s_game
{
	char		**map;
	int			map_lines;
	int			moves;
	void		*mlx;
	t_vector	*pp;
	t_vector	**ghosts;
	void		*window;
	int			coins;
	t_images	*images;
	int			g_n;
	int			map_height;
	int			map_width;
	int			moved;
	int			frame;
	int			dead;
	int			maxf;
	int			f;
}	t_game;

int			main(int ac, char **av);
int			control_init(int ac, char **av, t_game *game);
int			maps_check(char *av);
int			line_counter(char *av);
int			border_check(char **map, int lines);
int			invalid_char_check(char **map);
int			char_checker(char **map);
int			char_counter(char **map, char c);
int			path_finder(char **map);
t_vector	char_finder(char **map, char c);
void		flood(char **map, int x, int y);
void		free_check(int fd, char **map);
void		game_init(t_game *game);
char		**map_generator(char *av, t_game *game);
int			w_counter(char *line);
t_vector	**ghost_creator(t_game *game);
void		ghost_init(t_game *game, t_vector *ghost);
void		ghosts_init(t_game *game);
void		image_creator(t_images *images, void *mlx, int ww, int wh);
void		door_anim(t_images *images, void *mlx, int wdt);
void		player_init(t_game *game);
int			input_manager(int keycode, t_game *game);
int			md(t_game *game, int y, int x);
int			sfree(t_game *game);
int			updater(t_game *game);
void		image_updater(char c, int x, int y, t_game *game);
void		door_updater(t_game *game, int x, int y, t_images *images);
void		door_updater_2(t_game *game, int x, int y, int u);
void		render(t_game *game);
void		ghost_manager(t_game *game);
void		ghost_render(t_game *game, t_vector *ghost);
void		player_render(t_game *game);
void		moves_counter(t_game *game);
char		*ft_itoa(int n);
size_t		ft_count(long int i);
char		*ft_logic(char *s, size_t count, size_t i, int n);
int			ft_abs(int nb);
void		ft_death(t_game *game);
void		ft_close(t_game *game);
void		map_destroyer(char **map);
void		image_destroyer(t_images *i, void *m);
void		door_destroyer(t_images *i, void *m);

#endif
