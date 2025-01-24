/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:08:57 by myiu              #+#    #+#             */
/*   Updated: 2024/08/25 16:08:59 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_size(int number)
{
	int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static char	*min_int(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 12);
	if (result == NULL)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

static int	negative(int n, char *result)
{
	int	number;

	result[0] = '-';
	number = -n;
	return (number);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		number;
	int		length;

	length = ft_number_size(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	if (n == -2147483648)
		return (min_int());
	if (n < 0)
		number = negative(n, result);
	else
		number = n;
	if (number == 0)
		result[0] = '0';
	result[length] = '\0';
	while (number != 0)
	{
		result[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (result);
}
