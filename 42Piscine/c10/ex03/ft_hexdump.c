/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:29:52 by myiu              #+#    #+#             */
/*   Updated: 2024/07/24 12:42:57 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_file_size(char *file_name);
char	*ft_copy_input(char *file_name, int size);
void	ft_print_line(int offset, char *buf, int size);
int		compare_buffers(char *buf1, char *buf2, int size);
void	copy_buffer(char *dest, char *src, int size);
int		is_identical(int ret, int offset, char *buf, char *prev_buf);
void	initialize_buffer(char *buf, int size);

void	ft_print_offset(int n)
{
	const char	*base;
	char		buffer[9];
	int			i;

	i = 8;
	base = "0123456789abcdef";
	buffer[8] = '\0';
	while (i > 0)
	{
		buffer[--i] = base[n % 16];
		n /= 16;
	}
	write(1, buffer, 8);
}

void	ft_print_hex(char *buf, int size)
{
	const char	base[16] = "0123456789abcdef";
	int			i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			write(1, &base[(buf[i] >> 4) & 0xF], 1);
			write(1, &base[buf[i] & 0xF], 1);
		}
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (i % 8 == 7)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_ascii(char *buf, int size)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (i < size)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	ft_hexdump(char *file_name, int *offset_ptr)
{
	int		fd;
	int		ret;
	char	buf[16];
	char	prev_buf[16];

	fd = open(file_name, O_RDONLY);
	ret = read(fd, buf, sizeof(buf));
	initialize_buffer(prev_buf, 16);
	if (fd < 0)
	{
		write(2, "./ft_hexdump: ", 14);
		while (*file_name)
			write(2, file_name++, 1);
		write(2, ": No such file or directory\n", 28);
		return ;
	}
	while (ret > 0)
	{
		*offset_ptr = is_identical(ret, *offset_ptr, buf, prev_buf);
		ret = read(fd, buf, sizeof(buf));
	}
	if (ret > 0 || compare_buffers(buf, prev_buf, 16))
		ft_print_line(*offset_ptr, buf, ret);
}

int	main(int argc, char **argv)
{
	int	i;
	int	offset;

	i = 1;
	offset = 0;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && (argv[i][1] == 'C')))
			ft_hexdump(argv[i], &offset);
		i++;
	}
	if (offset > 0)
	{
		ft_print_offset(offset);
		write(1, "\n", 1);
	}
	return (0);
}
