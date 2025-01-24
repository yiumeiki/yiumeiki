/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:41:13 by myiu              #+#    #+#             */
/*   Updated: 2024/07/25 15:20:56 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_isnum	is_numeric(char *num_str)
{
	int		i;
	int		nbr;
	int		is_num;
	t_isnum	res;

	is_num = 1;
	i = 0;
	nbr = 0;
	while (num_str[i] != '\0')
	{
		if (num_str[i] < '0' || num_str[i] > '9')
			is_num = 0;
		else
			nbr = (nbr * 10) + (num_str[i] - '0');
		i++;
	}
	res.nbr = nbr;
	res.is_num = is_num;
	return (res);
}

void	err_check(char *file_name, char *binary, int err_nb)
{
	int	f;

	if (err_nb == 0)
	{
		f = open(file_name, O_RDONLY);
		if (f < 0)
		{
			write(2, binary, ft_strlen(binary));
			write(2, ": cannot open '", 15);
			write(2, file_name, ft_strlen(file_name));
			write(2, "' for reading: ", 15);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
		}
		close(f);
		return ;
	}
	write(2, binary, ft_strlen(binary));
	if (err_nb == 1)
		write(2, ": invalid number of bytes: '", 28);
	else if (err_nb == 2)
		write(2, ": invalid option -- '", 21);
	write(2, file_name, ft_strlen(file_name));
	write(2, "'\n", 2);
}

void	ft_tail(char *file_name, int tail_n, int mult_files, int first)
{
	char	buffer[30000];
	int		f;
	int		size;
	int		start;

	f = open(file_name, O_RDONLY);
	if (mult_files == -1)
		f = STDIN_FILENO;
	if (f < 0)
		return ;
	size = read(f, buffer, 30000);
	start = 0;
	if (size > tail_n)
		start = size - tail_n;
	if (size > 0)
	{
		if (first != 1)
			write(1, "\n", 1);
		if (mult_files == 1)
			multi_write(file_name);
		write(1, buffer + start, size - start);
	}
	close(f);
}

void	exec_order(int argc, char **argv, t_isnum nbr)
{
	int	i;
	int	mult_files;

	mult_files = 0;
	if (argc == 3)
		ft_tail(0, nbr.nbr, -1, 1);
	i = 3;
	if (argc > 4)
		mult_files = 1;
	i = 3;
	while (i < argc)
	{
		err_check(argv[i], argv[0], 0);
		if (i == 3)
			ft_tail(argv[i], nbr.nbr, mult_files, 1);
		else
			ft_tail(argv[i], nbr.nbr, mult_files, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_isnum	nbr;	

	if (argc == 1)
	{
		ft_tail("stdin", 30000, -1, 1);
		return (0);
	}
	if (ft_strcmp(argv[1], "-c") == 0)
	{
		if (argv[2][0] == '0')
			return (0);
		nbr = is_numeric(argv[2]);
		if (nbr.is_num == 1)
			exec_order(argc, argv, nbr);
		else
			err_check(argv[2], argv[0], 1);
	}
	else
		err_check(argv[1], argv[0], 2);
}
