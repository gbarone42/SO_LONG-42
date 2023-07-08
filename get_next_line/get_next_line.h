/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:24:12 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/23 12:25:26 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_reads( int fd, char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *s);
char	*ft_new_line(char *s);

#endif
