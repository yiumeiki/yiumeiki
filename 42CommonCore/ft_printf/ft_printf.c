/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:54:16 by myiu              #+#    #+#             */
/*   Updated: 2024/08/30 12:54:18 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	call different functions to handle different "%"
*/
static void	check_input(char s, va_list *args, int *len, int *index)
{
	if (s == 's')
		for_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		for_int(va_arg(*args, int), len);
	else if (s == 'u')
		for_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		for_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		for_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		for_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*index)--;
}

/*
	to initialise and check input( '%' ? call other functions : print directly)
	return the total number of char printed(length) like printf
*/
int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		index;
	int		length;

	index = 0;
	length = 0;
	va_start(args, string);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			index++;
			check_input(string[index], &args, &length, &index);
			index++;
		}
		else
		{
			ft_putchar_len((char)string[index], &length);
			index++;
		}
	}
	va_end(args);
	return (length);
}
/*
#include <stdio.h>
int main()
{
	//int* a = NULL;
	int b = 18;
	//ft_printf("%p\n",NULL);
	//printf("%p\n",NULL);
	ft_printf("%X\n", b);
	printf("%X\n", b);
}
*/
