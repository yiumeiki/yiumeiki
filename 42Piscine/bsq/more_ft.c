/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:14:50 by myiu              #+#    #+#             */
/*   Updated: 2024/07/24 17:23:58 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	too_long_for_error(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int	no_wrong_chars(char *str_map, t_map_params *map_params)
{
	int	i;

	i = 0;
	while (str_map[i] != '\0')
	{
		if (str_map[i] != map_params->obs && str_map[i] != map_params->emp \
				&& str_map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
