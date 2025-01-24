/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:12:06 by myiu              #+#    #+#             */
/*   Updated: 2024/07/09 12:56:30 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	sizeof_range;
	int	index;
	int	*address;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	sizeof_range = max - min;
	address = malloc(sizeof_range * 4);
	if (!address)
	{
		*range = 0;
		return (-1);
	}
	*range = address;
	index = 0;
	while (index < sizeof_range)
	{
		address[index] = min + index;
		index++;
	}
	return (sizeof_range);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i = 0;

	min = 5;
	max = 10;
	size = ft_ultimate_range(&tab, min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}*/
