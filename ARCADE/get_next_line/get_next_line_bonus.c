/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:13:14 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/20 19:14:36 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reads( int fd, char *s)
{
	char	*buff;
	int		rd_byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchr(s, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{	
			if (s != NULL)
				free(s);
			free(buff);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s[fd] = ft_reads(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = ft_get_line(s[fd]);
	s[fd] = ft_new_line(s[fd]);
	return (line);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		//line = get_next_line(fd3);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}*/
