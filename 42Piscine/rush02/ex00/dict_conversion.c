/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:20:32 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/21 22:51:04 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"

void	dict_searcher(char *nbr, t_dict nbr_dict, int first)
{
	int	i;

	i = 0;
	while (i < nbr_dict.size)
	{
		if (ft_strcmp(nbr, nbr_dict.nbr_key[i]) == 0)
		{
			if (first < 1)
				write(1, " ", 1);
			write(1, nbr_dict.str_vals[i], ft_strlen(nbr_dict.str_vals[i]));
			return ;
		}
		i++;
	}
	write(1, "Dict Error\n", 11);
	exit(0);
}

int	tens_conversion(char *buffer, int nbr, int *first, t_dict nbr_dict)
{
	buffer[0] = (nbr / 10) + '0';
	buffer[1] = '0';
	if (buffer[0] == '1')
	{
		buffer[1] = (nbr % 10) + '0';
		dict_searcher(buffer, nbr_dict, *first);
		return (1);
	}
	buffer[1] = '0';
	dict_searcher(buffer, nbr_dict, *first);
	*first = *first - 1;
	return (0);
}

void	hundred_conversion(char *nbr_str, t_dict nbr_dict, int first)
{
	char	buffer[3];
	int		nbr;

	nbr = ft_atoi(nbr_str);
	if (nbr / 100 >= 1)
	{
		buffer[0] = (nbr / 100) + '0';
		buffer[1] = '\0';
		dict_searcher(buffer, nbr_dict, first);
		first -= 1;
		dict_searcher("100", nbr_dict, 0);
		nbr %= 100;
	}
	if (nbr / 10 >= 1)
	{
		if (tens_conversion(buffer, nbr, &first, nbr_dict) == 1)
			return ;
	}
	nbr %= 10;
	if (nbr > 0)
	{
		buffer[0] = nbr + '0';
		buffer[1] = '\0';
		dict_searcher(buffer, nbr_dict, first);
	}
}

int	if_zero(char *file_path, char *str_clear)
{
	t_dict	nbr_dict;

	if (ft_strcmp(str_clear, "0") == 0)
	{
		nbr_dict = dict_conversion(file_path);
		dict_searcher("0", nbr_dict, 1);
		write(1, "\n", 1);
		free_struct(&nbr_dict);
		return (0);
	}
	return (1);
}

void	free_struct(t_dict *nbr_dict)
{
	int	i;

	i = 0;
	while (i < nbr_dict->size)
	{
		free(nbr_dict->nbr_key[i]);
		free(nbr_dict->str_vals[i]);
		i++;
	}
	free(nbr_dict->nbr_key[i]);
	free(nbr_dict->str_vals[i]);
	free(nbr_dict->nbr_key);
	free(nbr_dict->str_vals);
}
