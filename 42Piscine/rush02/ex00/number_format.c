/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:59:01 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/21 22:37:58 by jkaucky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"

char	*ft_str_clear(char **argv, int arg_n)
{
	int		i;
	int		j;
	char	*str_clear;

	i = 0;
	j = 0;
	str_clear = (char *)malloc(j + 1);
	while ((argv[arg_n][i] && argv[arg_n][i] == ' ')
		|| (argv[arg_n][i] >= 9 && argv[arg_n][i] <= 13))
		i++;
	if (argv[arg_n][i] && argv[arg_n][i] == '+')
		i++;
	while (argv[arg_n][i])
	{
		str_clear[j] = argv[arg_n][i];
		j++;
		i++;
	}
	str_clear[j] = '\0';
	return (str_clear);
}

void	print_big_nbr(int j, char *three_digi, int start, char *file_path)
{
	char	*unit;
	t_dict	nbr_dict;
	int		index;
	int		num_zeros;

	num_zeros = (j - 1) / 3 * 3;
	nbr_dict = dict_conversion(file_path);
	unit = malloc(num_zeros + 2);
	if (j > 0)
	{
		unit[0] = '1';
		unit[num_zeros + 1] = '\0';
		index = 1;
		while (index < (num_zeros + 1))
		{
			unit[index] = '0';
			index++;
		}
		hundred_conversion(three_digi, nbr_dict, start);
		if (num_zeros > 0 && ft_strcmp(three_digi, "000") != 0)
			dict_searcher(unit, nbr_dict, 0);
	}
	free_struct(&nbr_dict);
	free(unit);
}

int	process_initial_chars(char *str_clear, char *three_digi, int len)
{
	int	i;

	i = 0;
	three_digi[0] = str_clear[i];
	three_digi[3] = '\0';
	if (len % 3 == 0)
	{
		three_digi[1] = str_clear[++i];
		three_digi[2] = str_clear[++i];
	}
	else if (len % 3 == 2)
	{
		three_digi[1] = str_clear[++i];
		three_digi[2] = '\0';
	}
	else if (len % 3 == 1)
		three_digi[1] = '\0';
	return (i);
}

void	big_number(char *str_clear, char *file_path)
{
	int		i;
	int		j;
	int		k;
	char	three_digi[4];

	k = ft_strlen(str_clear);
	j = k;
	i = process_initial_chars(str_clear, three_digi, j);
	i++;
	if (j > 3)
	{
		if (j % 3 == 0)
			j -= 3;
		j = (j - (j % 3));
	}
	print_big_nbr(k, three_digi, 1, file_path);
	while (str_clear[i] != '\0')
	{
		big_num2(j, str_clear, i, file_path);
		j -= 3;
		i += 3;
	}
}

void	big_num2(int j, char *str_clear, int i, char *file_path)
{
	char	three_digi[4];

	three_digi[0] = str_clear[i];
	three_digi[1] = str_clear[++i];
	three_digi[2] = str_clear[++i];
	three_digi[3] = '\0';
	print_big_nbr(j, three_digi, 0, file_path);
}
