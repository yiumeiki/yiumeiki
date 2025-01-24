/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:07:22 by myiu              #+#    #+#             */
/*   Updated: 2024/07/08 17:50:16 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	index;
	int	*arr;

	if (min >= max)
		return (NULL);
	range = max - min;
	arr = malloc(range * sizeof(int));
	index = 0;
	while (index < range)
	{
		arr[index] = min + index;
		index++;
	}
	return (arr);
}
/*
int		main(void)
{
	int	min;
	int	max;
	int	*arr;
	int	i = 0;
	int	size;

	min = 5;
	max = 10;
	size = max - min;
	arr = ft_range(min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}*/
