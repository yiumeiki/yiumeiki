/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:08:13 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
	update the stat str (the static buffer) after a line has been read
	remove the part of stat that has already been read 
	and leaves the remaining content
*/
static char	*remain_stat(char *stat)
{
	int		i;
	int		start;
	char	*remain;

	i = 0;
	if (stat[i] == '\0')
	{
		free(stat);
		return (NULL);
	}
	while (stat[i] != '\n' && stat[i])
		i++;
	if (stat[i] == '\n')
		i++;
	start = i;
	i = 0;
	remain = (char *)malloc((ft_strlen(stat) - start + 1) * sizeof(char));
	if (!remain)
		return (NULL);
	start--;
	while (stat[++start])
		remain[i++] = stat[start];
	remain[i] = '\0';
	free(stat);
	return (remain);
}

/*
	extract the next line from the stat string
	read from the beginning of stat until it finds the newline (\n)
	returns that part as a new string
*/
static char	*get_line(char	*stat)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (stat[i] == 0)
		return (NULL);
	while (stat[len] != '\n' && stat[len])
		len++;
	if (stat[len] == '\n')
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (i < len)
	{
		line[i] = stat[i];
		i++;
	}
	return (line);
}

/*
	reading from the file descriptor "fd" and appending the content to stat
	continues reading until it encounters a newline or the end of the file
*/
static char	*putstat(int fd, char *stat)
{
	int		val;
	char	*buffer;

	val = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!charset(stat) && val != 0)
	{
		val = read(fd, buffer, BUFFER_SIZE);
		if (val < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[val] = '\0';
		stat = strjoin(stat, buffer);
		if (!stat)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stat);
}

/*
	uses the previous helper functions to read the line
	update the state, and return the result
*/
char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = putstat(fd, stat);
	if (!stat)
	{
		free(stat);
		return (NULL);
	}
	line = get_line(stat);
	stat = remain_stat(stat);
	if (!stat)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
