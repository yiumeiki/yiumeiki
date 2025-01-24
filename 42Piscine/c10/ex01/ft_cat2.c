/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:15:11 by myiu              #+#    #+#             */
/*   Updated: 2024/07/18 20:18:04 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>

int		ft_strlen(char *str);
void	write_str(int fd, char *str);
void	print_error(char *filepath, char *program_name);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	write_str(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void	print_error(char *filepath, char *name)
{
	char	*error_message;

	error_message = strerror(errno);
	write_str(2, name);
	write(2, ": ", 2);
	write_str(2, filepath);
	write(2, ": ", 2);
	write_str(2, error_message);
	write(2, "\n", 1);
}
