/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:41:30 by myiu              #+#    #+#             */
/*   Updated: 2024/07/25 15:28:22 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# define FT_H

typedef struct s_isnum
{
	int	nbr;
	int	is_num;
}	t_isnum;

int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
void	multi_write(char *file_name);
t_isnum	is_numeric(char *num_str);
void	err_check(char *file_name, char *binary, int err_nb);
void	ft_tail(char *file_name, int tail_n, int mult_files, int first);
void	exec_order(int argc, char **argv, t_isnum nbr);
int		main(int argc, char **argv);

#endif
