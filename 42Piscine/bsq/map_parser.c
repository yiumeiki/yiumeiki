/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:22:03 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/24 17:23:42 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Reads map as a str; ft_splits it based on '\n' character; checks each line len
int	str_param_err_c(t_map_params *map_params, char *str_map, char *file_name)
{
	int		fd;
	int		i;
	int		line_len;
	char	c;

	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		continue ;
	i = 0;
	while (read(fd, &c, 1) > 0)
		str_map[i++] = c;
	if (no_wrong_chars(str_map, map_params) == 1)
		return (1);
	map_params->map = ft_split(str_map, "\n");
	i = 0;
	while (map_params->map[i + 1] != NULL)
	{
		line_len = ft_strlen(map_params->map[i]);
		if (line_len - ft_strlen(map_params->map[i + 1]) != 0)
			return (1);
		i++;
	}
	map_params->width = line_len;
	return (0);
}

//Converts the string params to the struct format and mallocs for the string
t_map_params	s_params_to_t_params(char *s_params, char *file_n, int map_len)
{
	int				len;
	int				i;
	int				res;
	char			*str_map;
	t_map_params	map_params;

	map_params.map_error = 'O';
	str_map = malloc((map_len + 1) * sizeof(char));
	len = ft_strlen(s_params);
	map_params.full = s_params[len - 1];
	map_params.obs = s_params[len - 2];
	map_params.emp = s_params[len - 3];
	i = 0;
	res = 0;
	while (i < len - 3)
		res = (res * 10) + (s_params[i++] - '0');
	map_params.lines = res;
	if (param_err_c(&map_params) == 1 \
			|| str_param_err_c(&map_params, str_map, file_n) == 1)
	{
		write(2, "map error\n", 10);
		map_params.map_error = 'E';
	}
	return (map_params);
}

int	line_checker(char *file_name, t_map_params *map_params)
{
	unsigned int	i;
	int				fd;
	unsigned int	actual_lines;
	char			c;
	unsigned int	final_new_line;

	actual_lines = 0;
	final_new_line = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		continue ;
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (actual_lines == map_params->lines - 1)
			if (c == '\n')
				final_new_line = 1;
		if (c == '\n')
			actual_lines++;
	}
	if ((actual_lines != map_params->lines || final_new_line == 0) \
			&& map_params->map_error != 'E')
		return (too_long_for_error());
	return (0);
}

//Reads the maps and converts its first line into a string and counts the rest
t_map_params	map_to_s_params(char *file_name)
{
	t_map_params	map_params;
	char			c;
	char			map_param_str[13];
	int				fd;
	int				i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	read(fd, &c, 1);
	while (c != '\n')
	{
		map_param_str[i] = c;
		read(fd, &c, 1);
		i++;
	}
	map_param_str[i] = '\0';
	read(fd, &c, 1);
	i = 0;
	while (read(fd, &c, 1) > 0)
		i++;
	map_params = s_params_to_t_params(map_param_str, file_name, i);
	if (line_checker(file_name, &map_params) == 1)
		map_params.map_error = 'E';
	return (map_params);
}

int	main(int argc, char **argv)
{
	t_map_params	map_params;
	int				i;

	if (argc == 1)
		write(1, "Please enter map file", 21);
	i = 1;
	while (i < argc)
	{
		map_params = map_to_s_params(argv[i]);
		if (map_params.map_error != 'E')
		{
			read_hori(map_params);
		}
		if (i != (argc - 1))
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
