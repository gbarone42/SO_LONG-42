/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:59:23 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 00:34:15 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(char **map)
{
	t_vector	exit;
	t_vector	p;

	p = char_finder(map, 'P'); // function simply searches for the position of a given character on the map and returns its position as a t_vector struct.
	exit = char_finder(map, 'E');
	flood(map, exit.x, exit.y);
	if (map[p.y][p.x] != '1')
		return (1);
	if (char_counter(map, 'C') != 0) //this function counts the number of occurrences of a given character on the map.
		return (1);
	return (0);
}

void	flood(char **map, int x, int y) //flood-fill algorithm
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood(map, x + 1, y);
	flood(map, x - 1, y);
	flood(map, x, y + 1);
	flood(map, x, y - 1);
}

/*

//The flood function recursively floods the map starting from the given position (x, y), marking all reachable positions with '1'.
//marking all positions that can be reached from the exit. If the player is able to reach any of these positions, there is a path from the player to the exit.

//The flood function works by checking if the current cell in the map is a wall (value of '1'). If it is, then the function simply returns without doing anything.
//If the current cell is not a wall, it changes the value of the current cell to '1', indicating that the cell has been visited.
//The coordinates of the adjacent cells to the current cell, which are obtained by adding or subtracting 1 from the x or y coordinates of the current cell.


This process continues until all reachable cells have been marked as visited, and the function returns. The path_finder function then checks if the starting position 'P' is reachable 
from the exit position 'E' by checking the value of the cell at the starting position. If it is not '1', then the starting position is reachable and the function returns 0, indicating that the map is valid.




*/
void	free_check(int fd, char **map)
{
	int	i;

	i = 0;
	close(fd);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}
/*
The free_check function iterates over the map array and calls free on each string. It then calls free on the map array itself and closes the file.
*/
