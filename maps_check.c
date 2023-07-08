/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:59:23 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 00:34:13 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	maps_check(char *av)//file
{
	int		fd;
	int		lines;
	char	**map;
	int		i;
	int		error;

	error = 0;
	i = 0;
	fd = open(av, O_RDWR);
	if (fd == -1)
		ft_printf("\033[0;31mThe Map cannot be openedd. Does the Map exist?\n\033[0;37m");
	if (read(fd, 0, 0) == -1 || fd < 0)
		return (1);
	lines = line_counter(av); //count number on lines
	map = malloc(sizeof(char *) * (lines + 1)); //allocates memory for map (an array of strings) and reads each line of the file into map
	map[lines] = NULL;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	error += border_check(map, lines);
	error += char_checker(map);
	if (error == 0)
		error += path_finder(map); //check if there is a valid path from the starting position 'P' to the exit position 'E'.
	free_check(fd, map); //function is called to free the memory allocated for the map array
	return (error);
}
*/
int	line_counter(char *av)//file
{
	char	c;
	int		c_read;
	int		fd;
	int		lines;

	c_read = 1;
	lines = 0;
	fd = open(av, O_RDWR); //The open() function shall establish the connection between a file and a file descriptor.
	while (c_read)
	{
		c_read = read(fd, &c, 1); //The read() function shall attempt to read nbyte bytes from the file associated with the open file descriptor, fildes, into the buffer pointed to by buf.
					//it reads the file one character at a time 
		if (c == '\n' && c_read)
			lines++;
	}
	if (c != '\n')
		lines++;
	close(fd); //The close() function shall deallocate the file descriptor indicated by fildes.
	return (lines);
}

int	border_check(char **map, int lines) //the map is a 2D array
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] == '1') //iterating through the first line of the map until it finds the first character that is not a "1"
		i++;
	if (map[0][i] != '\n')
		return (1); // If this character is not a newline character
	j = i - 1; //It also sets the variable "j" to the index of the last "1" character on the top border.
	i = 0;
	while (map[lines - 1][i] == '1') //iterating through the last line of the map until it finds the first character that is not a "1"
		i++;
	if (map[lines - 1][i] != '\0' && map[lines - 1][i] != '\n')
		return (1); //If this character is not a null character or newline character, it returns 1.
	i = 0;
	while (i < lines)
	{
		if (map[i][0] != '1' || map[i][j] != '1') //checks the left and right borders of the map by iterating through each line of the map and checking the first and last characters
			return (1); //if any of these characters are not "1" it's error
		i++;
	}
	i = invalid_char_check(map); //If "invalid_char_check" returns 1, "border_check" also returns 1
	return (i);
}

int	maps_check(char *av)//file
{
	int		fd;
	int		lines;
	char	**map;
	int		i;
	int		error;

	error = 0;
	i = 0;
	fd = open(av, O_RDWR);
	if (fd == -1)
		ft_printf("\033[0;31mThe Map cannot be openedd. Does the Map exist?\n\033[0;37m");
	if (read(fd, 0, 0) == -1 || fd < 0)
		return (1);
	lines = line_counter(av); //count number on lines
	map = malloc(sizeof(char *) * (lines + 1)); //allocates memory for map (an array of strings) and reads each line of the file into map
	map[lines] = NULL;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	error += border_check(map, lines);
	error += char_checker(map);
	if (error == 0)
		error += path_finder(map); //check if there is a valid path from the starting position 'P' to the exit position 'E'.
	free_check(fd, map); //function is called to free the memory allocated for the map array
	return (error);
}
