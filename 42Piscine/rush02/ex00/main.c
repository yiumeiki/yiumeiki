/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:50:02 by myiu              #+#    #+#             */
/*   Updated: 2024/07/21 23:34:01 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	is_num(char *str)
{
	int	i;
	int	is_num;

	i = 0;
	is_num = 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			is_num = 0;
		}
		i++;
	}
	if (is_num == 0)
	{
		write(1, "Dict Error\n", 11);
		exit(0);
	}
}

void	argc_is_two(char *str_clear)
{
	is_num(str_clear);
	if (ft_strcmp(str_clear, "0") == 0)
		write(1, "zero", 4);
	big_number(str_clear, "numbers.dict");
}

int	main(int argc, char **argv)
{
	char	*str_clear;

	if (!(argc == 2 || argc == 3) || str_len(argv) > 40)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2 && str_len(argv) <= 40)
	{
		str_clear = ft_str_clear(argv, 1);
		argc_is_two(str_clear);
	}
	if (argc == 3)
	{
		str_clear = ft_str_clear(argv, 2);
		is_num(str_clear);
		if (if_zero(argv[1], str_clear) == 0)
			return (0);
		big_number(str_clear, argv[1]);
	}
	write(1, "\n", 1);
	free(str_clear);
	return (0);
}
