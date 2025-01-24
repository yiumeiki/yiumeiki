/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:41:37 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/21 17:28:03 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	values_formatting(t_dict *nbr_dict, int lines, int val_c)
{
	char	*val;
	int		val_inc;
	int		i;

	while (val_c < lines)
	{
		val = nbr_dict->str_vals[val_c];
		i = 0;
		while (val[i] == ' ' && val[i] != '\0')
			i++;
		val_inc = 0;
		while (val[i] != '\0')
		{
			if ((val[i] == ' ' && val[i - 1] == ' ' && i > 0) || val[i] == '\n')
				i++;
			else
			{
				nbr_dict->str_vals[val_c][val_inc] = val[i];
				val_inc++;
				i++;
			}
		}
		nbr_dict->str_vals[val_c][val_inc] = '\0';
		val_c++;
	}
}

int	str_len(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((argv[1][i] && argv[1][i] == ' ')
		|| (argv[1][i] >= 9 && argv[1][i] <= 13))
		i++;
	if (argv[1][i] && argv[1][i] == '+')
		i++;
	while (argv[1][i] && argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *nbr, char *key)
{
	while (*nbr && (*nbr == *key))
	{
		nbr++;
		key++;
	}
	return (*nbr - *key);
}
