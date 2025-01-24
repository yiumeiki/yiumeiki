/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:41:55 by myiu              #+#    #+#             */
/*   Updated: 2025/01/15 17:09:18 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
	str: Input string to check.
	int flag: indicating a signal operation status.
	If the string contains invalid characters or the flag indicates
	an error (-1), prints an error message and exits the program.
 */
void	ft_error(const char *str, int flag)
{
	while (*str)
	{
		if (*str != 32)
		{
			write(1, "Error input\n", 12);
			exit (1);
		}
		str++;
	}
	if (flag == -1)
	{
		write(1, "Error input\n", 12);
		exit (1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*	print number*/
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

int	ft_atoi(const char *str)
{
	unsigned int	result;

	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	ft_error(str, 0);
	return (result);
}
