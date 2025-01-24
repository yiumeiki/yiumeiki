/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:27:21 by myiu              #+#    #+#             */
/*   Updated: 2024/07/24 17:29:15 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	param_err_c(t_map_params *map_params)
{
	if (map_params->full == map_params->obs \
			|| map_params->full == map_params->emp \
			|| map_params->obs == map_params->emp)
		return (1);
	if (map_params->lines < 1)
	{
		return (1);
	}
	return (0);
}

void	print_map(int x, int y, int sqr_side, t_map_params map_params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sqr_side)
	{
		while (j < sqr_side)
		{
			map_params.map[y + i][x + j] = map_params.full;
			j++;
		}
		j = 0;
		i++;
	}
	ft_putchar(map_params);
}

void	ft_putchar(t_map_params map_params)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (map_params.lines == 1)
	{
		write(1, map_params.map[0], ft_strlen(map_params.map[0]));
		write(1, "\n", 1);
		return ;
	}
	while (i < map_params.lines)
	{
		j = 0;
		while (j < map_params.width)
		{
			write(1, &map_params.map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
