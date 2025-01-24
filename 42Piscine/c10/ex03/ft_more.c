/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:40:00 by myiu              #+#    #+#             */
/*   Updated: 2024/07/24 12:39:46 by myiu             ###   ########.fr       */
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
void	ft_print_offset(int n);
void	ft_print_hex(char *buf, int size);
void	ft_print_ascii(char *buf, int size);
void	ft_hexdump(char *file_name);
int		main(int argc, char **argv);

int	is_identical(int ret, int offset, char *buf, char *prev_buf)
{
	static int	identical;

	identical = 0;
	if (ret == 16 && compare_buffers(buf, prev_buf, 16))
	{
		if (!identical)
		{
			write(1, "*\n", 2);
			identical = 1;
		}
	}
	else
	{
		if (identical)
			identical = 0;
		ft_print_line(offset, buf, 16);
	}
	copy_buffer(prev_buf, buf, 16);
	return (offset + ret);
}

void	initialize_buffer(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buf[i] = 0;
		i++;
	}
}
