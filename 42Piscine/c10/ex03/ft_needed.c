/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:13:56 by myiu              #+#    #+#             */
/*   Updated: 2024/07/22 21:56:32 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print_offset(int n);
void	initialize_buffer(char *buf, int size);
void	ft_print_hex(char *buf, int size);
void	ft_print_ascii(char *buf, int size);
int		is_identical(int ret, int offset, char *buf, char *prev_buf);
void	ft_hexdump(char *file_name);
int		main(int argc, char **argv);

void	ft_print_line(int offset, char *buf, int size)
{
	ft_print_offset(offset);
	write(1, "  ", 2);
	ft_print_hex(buf, size);
	ft_print_ascii(buf, size);
}

int	compare_buffers(char *buf1, char *buf2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buf1[i] != buf2[i])
			return (0);
		i++;
	}
	return (1);
}

void	copy_buffer(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	ft_file_size(char *file_name)
{
	char	buffer;
	int		size;
	int		file_desc;

	buffer = 0;
	size = 0;
	file_desc = open(file_name, O_RDONLY);
	if (file_desc < 0)
	{
		write(2, "ft_hexdump: ", 12);
		while (*file_name)
			write(2, file_name++, 1);
		write(2, ": No such file or directory\n", 28);
	}
	else
		while (read(file_desc, &buffer, 1) > 0)
			++size;
	close(file_desc);
	return (size);
}

char	*ft_copy_input(char *file_name, int size)
{
	char	buffer;
	int		i;
	char	*str;
	int		file_desc;

	buffer = 0;
	i = 0;
	str = malloc(size + 1);
	file_desc = open(file_name, O_RDONLY);
	i = 0;
	while (read(file_desc, &buffer, 1) > 0)
		str[i++] = buffer;
	str[i] = '\0';
	close(file_desc);
	return (str);
}
