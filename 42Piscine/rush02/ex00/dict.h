/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:27:17 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/21 23:05:41 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	**nbr_key;
	char	**str_vals;
	int		size;
}	t_dict;

void	is_num(char *str);
int		process_initial_chars(char *str_clear, char *three_digi, int len);
void	struct_malloc(t_dict *nbr_dict, char *file_path);
int		file_open(char *file_path);
void	key_reader(int f, char c, t_dict *nbr_dict, int line);
t_dict	dict_conversion(char *file_path);
int		ft_strcmp(char *nbr, char *key);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		str_len(char **argv);
char	*ft_str_clear(char **argv, int arg_n);
void	print_big_nbr(int j, char *three_digi, int i, char *file_path);
void	big_number(char *str_clear, char *file_path);
void	big_num2(int j, char *str_clear, int i, char *file_path);
void	dict_searcher(char *nbr, t_dict nbr_dict, int first);
int		tens_conversion(char *buffer, int nbr, int *first, t_dict nbr_dict);
void	hundred_conversion(char *nbr_str, t_dict nbr_dict, int first);
int		line_counter(char *file_name);
void	values_formatting(t_dict *nbr_dict, int line, int val_c);
int		if_zero(char *file_path, char *str_clear);
void	free_struct(t_dict *nbr_dict);
void	argc_is_two(char *str_clear);

#endif
