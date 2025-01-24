/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:40:29 by myiu              #+#    #+#             */
/*   Updated: 2024/11/28 17:13:21 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	for "%d", int_min ? print directly : process by other functions
*/
void	for_int(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar_len('-', length);
		for_int(number * -1, length);
	}
	else
	{
		if (number > 9)
			for_int(number / 10, length);
		ft_putchar_len(number % 10 + '0', length);
	}
}

/*
	for "%p", null ? print directly : change base to hex and print address
	process from the end, print in reverse way to have correct order
*/
void	for_pointer(size_t pointer, int *length)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		(*length) += write(1, "(nil)", 5);
		return ;
	}
	(*length) += 2;
	write(1, "0x", 2);
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(string[i], length);
	}
}

/*
	check x or X, and then change base to correct base
	process from the end, print in reverse way to have correct order
*/
void	for_hex(unsigned int x, int *length, char c)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (c == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], length);
}

/*
	print int
*/
void	for_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		for_unsigned_int(u / 10, length);
	ft_putchar_len(u % 10 + '0', length);
}
