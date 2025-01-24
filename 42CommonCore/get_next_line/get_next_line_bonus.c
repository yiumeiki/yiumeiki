/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:34:21 by myiu              #+#    #+#             */
/*   Updated: 2024/08/30 12:34:23 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	char		*buff;
	int			bytes_read;
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read_byte(buff, &rest[fd], 1, fd);
	if (bytes_read == -1)
		return (NULL);
	free(buff);
	line = ft_substr_line(rest[fd], 0, ft_strlen(rest[fd], '\n') + 1);
	rest[fd] = ft_substr_rest(rest[fd], ft_strlen(line, '\0'),
			ft_strlen(rest[fd], '\0') - ft_strlen(line, '\0'));
	if (bytes_read == 0 && ft_strlen(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*
int main()
{
	int fd1 = open("123.txt", O_RDONLY);
	int fd2 = open("abc.txt", O_RDONLY);
	printf("123:%s\n", get_next_line(fd1));
	printf("abc:%s\n", get_next_line(fd2));
}
*/