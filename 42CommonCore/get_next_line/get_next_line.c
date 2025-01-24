/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:12:50 by myiu              #+#    #+#             */
/*   Updated: 2024/12/03 17:07:36 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Reads data into buff using read in chunks of BUFFER_SIZE
	Checks if a newline character exists in rest
	Appends the content of buff to rest
	Stops reading when a \n is found or when read returns 0
*/
int	read_byte(char *buff, char **rest, int bytes_read, int fd)
{
	while (!check_line_break(*rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (-1);
		}
		buff[bytes_read] = '\0';
		*rest = ft_strjoin(*rest, buff);
	}
	return (bytes_read);
}

/*
	Calls read_byte ? free and return -1: return bytes_read
	Calls ft_substr_line to extract a single line from rest up to the first \n
	Updates rest with the remaining after the extracted line 
	Free when no more data is left
*/
char	*get_next_line(int fd)
{
	char		*buff;
	int			bytes_read;
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read_byte(buff, &rest, 1, fd);
	if (bytes_read == -1)
		return (NULL);
	free(buff);
	line = ft_substr_line(rest, 0, ft_strlen(rest, '\n') + 1);
	rest = ft_substr_rest(rest, ft_strlen(line, '\0'),
			ft_strlen(rest, '\0') - ft_strlen(line, '\0'));
	if (bytes_read == 0 && ft_strlen(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
