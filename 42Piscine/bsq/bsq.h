/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:08:55 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/24 17:31:10 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map_params
{
	unsigned int	lines;
	unsigned int	actual_lines;
	unsigned int	width;
	char			map_error;
	char			emp;
	char			obs;
	char			full;
	char			*map_as_str;
	char			**map;
}	t_map_params;

int		too_long_for_error(void);
int		in_cs(char c, char *charset);
char	**str_arr_malloc(char *str, char *charset);
char	*find_fill_substr(char *str, int start, int end);
int		no_wrong_chars(char *str_map, t_map_params *map_params);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *str1, char *str2);
int		column_checker(int x, int y, int length, t_map_params map_params);
int		read_vert(int x, int y, int length, t_map_params map_params);
int		hori_checker(int x, int y, int length, t_map_params map_params);
void	read_hori(t_map_params map_params);
int		param_err_c(t_map_params *map_params);
void	print_map(int x, int y, int sqr_side, t_map_params map_params);
void	print_map(int x, int y, int z, t_map_params map_params);
void	ft_putchar(t_map_params map_params);
int		iend(t_map_params map_params, int sqr_side, int hori_check, int line_n);

#endif
