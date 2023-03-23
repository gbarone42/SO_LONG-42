/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:55:41 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/20 23:49:53 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	aline_counter(char *av, t_game *game)
{
	char	c;
	int		c_read;
	int		fd;
	int		lines;

	c_read = 1;
	lines = 0;
	fd = open(av, O_RDWR);
	while (c_read)
	{
		c_read = read(fd, &c, 1);
		if (c == 'C')
			game->coins++;
		if (c == '\n' && c_read)
			lines++;
		if (c == 'G')
			game->g_n++;
	}
	if (c != '\n')
		lines++;
	close(fd);
	return (lines);
}

int	w_counter(char *line)//The w_counter function takes a string line as input and returns the width of the string multiplied by 50
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i * 50);
}

//The w_counter function takes a line of the map as an argument, and returns the width of the window needed to display that line of the map (presumably assuming a fixed character width).

//The multiplication by 50 is likely due to the fact that each character in the string represents a square on the game board, and the author of the code has decided to make each square 50 pixels wide.

char	**map_generator(char *av, t_game *game)
{
	int		fd;
	int		lines;
	char	**map;
	int		i;

	i = 0;
	lines = aline_counter(av, game); //calls aline_counter to get the number of lines in the file, then opens the file and reads it line by line using the get_next_line 
	fd = open(av, O_RDWR);
	map = malloc(sizeof(char *) * (lines + 1));
	map[lines] = NULL;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	game->map_lines = lines;
	game->w_h = lines * 50;
	game->w_w = w_counter(map[0]);
	return (map);
}
/*
static int	aline_counter(char *file, t_game *game)
{
	char	c;
	int		c_read;
	int		fd;
	int		lines;

	c_read = 1;
	lines = 0;
	fd = open(file, O_RDWR);
	while (c_read)
	{
		c_read = read(fd, &c, 1);
		if (c == 'C')
			game->coins++;
		if (c == '\n' && c_read)
			lines++;
		if (c == 'G')
			game->g_n++;
	}
	if (c != '\n')
		lines++;
	close(fd);
	return (lines);
}*/
