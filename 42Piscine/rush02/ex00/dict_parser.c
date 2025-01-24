/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:30:41 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/21 22:39:55 by jkaucky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"

void	struct_malloc(t_dict *nbr_dict, char *file_path)
{
	int	i;
	int	lines;

	lines = line_counter(file_path);
	nbr_dict->nbr_key = (char **)malloc(lines * sizeof(char *));
	nbr_dict->str_vals = (char **)malloc(lines * sizeof(char *));
	i = 0;
	while (i < lines)
	{
		nbr_dict->nbr_key[i] = (char *)malloc((1024) * sizeof(char));
		nbr_dict->str_vals[i] = (char *)malloc((1024) * sizeof(char));
		nbr_dict->nbr_key[i][0] = '\0';
		nbr_dict->str_vals[i][0] = '\0';
		i++;
	}
	nbr_dict->size = lines - 1;
}

int	file_open(char *file_path)
{
	int		f;

	f = open(file_path, O_RDONLY);
	if (f < 0)
	{
		write(1, "Dict Error\n", 11);
		exit(0);
	}
	return (f);
}

void	key_reader(int f, char c, t_dict *nbr_dict, int line)
{
	int	i;

	i = 0;
	while (c != ':')
	{
		if (c != ':' && c != ' ')
			nbr_dict->nbr_key[line][i++] = c;
		read(f, &c, 1);
	}
	nbr_dict->nbr_key[line][i] = '\0';
}

t_dict	dict_conversion(char *file_path)
{
	int			f;
	int			i;
	int			line;
	char		c;
	t_dict		nbr_dict;

	line = 0;
	c = ' ';
	struct_malloc(&nbr_dict, file_path);
	f = file_open(file_path);
	while (line < line_counter(file_path))
	{
		while ((line >= 1) && c == '\n')
			read(f, &c, 1);
		key_reader(f, c, &nbr_dict, line);
		i = 0;
		while (c != '\n' && (read(f, &c, 1) > 0))
			nbr_dict.str_vals[line][i++] = c;
		nbr_dict.str_vals[line][i] = '\0';
		line++;
	}
	close(f);
	values_formatting(&nbr_dict, line_counter(file_path), 0);
	return (nbr_dict);
}

int	line_counter(char *file_path)
{
	int		f;
	int		lines;
	char	c;

	f = file_open(file_path);
	lines = 0;
	while (read(f, &c, 1) > 0)
	{
		if (c == '\n')
			lines += 1;
	}
	return (lines);
}
