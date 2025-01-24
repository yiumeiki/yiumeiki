/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:38:40 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/23 23:01:23 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	column_checker(int x, int y, int length, t_map_params map_params)
{
	char	*empty_str;
	char	*column_str;
	int		i;
	int		diff;

	i = 0;
	empty_str = malloc(length + 1);
	column_str = malloc(length + 1);
	while (i < length)
	{
		empty_str[i] = map_params.emp;
		i++;
	}
	empty_str[i] = '\0';
	i = 0;
	while (i < length)
	{
		column_str[i] = map_params.map[y + i][x];
		i++;
	}
	column_str[i] = '\0';
	diff = ft_strcmp(column_str, empty_str);
	free(column_str);
	free(empty_str);
	return (diff);
}

int	read_vert(int x, int y, int length, t_map_params map_params)
{
	int	i;
	int	last_obs;

	i = 0;
	last_obs = -1;
	while (i < length)
	{
		if (column_checker(x + i, y, length, map_params) >= 0)
			last_obs = i;
		i++;
	}
	return (last_obs);
}

int	hori_checker(int x, int y, int length, t_map_params map_params)
{
	char	*empty_str;
	char	*row_str;
	int		i;
	int		diff;

	i = 0;
	empty_str = malloc(length + 1);
	row_str = malloc(length + 1);
	while (i < length)
		empty_str[i++] = map_params.emp;
	empty_str[i] = '\0';
	i = 0;
	while (i < length)
	{
		row_str[i] = map_params.map[y][x + i];
		i++;
	}
	row_str[i] = '\0';
	diff = ft_strcmp(empty_str, row_str);
	free(row_str);
	free(empty_str);
	return (diff);
}

int	iend(t_map_params map_params, int sqr_side, int i, int line_n)
{
	int	hori_check;

	hori_check = hori_checker(i, line_n, sqr_side, map_params);
	if (hori_check == -1)
	{
		if (read_vert(i, line_n, sqr_side, map_params) == -1)
		{
			print_map(i, line_n, sqr_side, map_params);
			return (10000000);
		}
		i++;
	}
	else
		i += hori_check + 1;
	return (i);
}

void	read_hori(t_map_params map_params)
{
	unsigned int	sqr_side;
	unsigned int	line_n;
	unsigned int	i;

	sqr_side = map_params.lines;
	if (map_params.width < sqr_side)
		sqr_side = map_params.width;
	while (sqr_side >= 1)
	{
		line_n = 0;
		while (line_n <= map_params.lines - sqr_side)
		{
			i = 0;
			while (i <= map_params.width - sqr_side)
			{
				i = iend(map_params, sqr_side, i, line_n);
				if (i == 10000000)
					return ;
			}
			line_n++;
		}
		sqr_side--;
	}
}
