/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:37:32 by myiu              #+#    #+#             */
/*   Updated: 2024/07/19 10:44:45 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>

void	ft_cat_stdin(void);
void	ft_cat(char *filepath, char *program_name);
void	print_error(char *filepath, char *program_name);

void	ft_cat_stdin(void)
{
	int		size;
	char	buf[30719];

	size = read(0, buf, 30719);
	while (size > 0)
	{
		write(1, buf, size);
		size = read(0, buf, 30719);
	}
}

void	ft_cat(char *filepath, char *program_name)
{
	int		file;
	int		size;
	char	buf[30719];

	file = open(filepath, O_RDONLY);
	if (file == -1)
	{
		print_error(filepath, program_name);
		return ;
	}
	size = read(file, buf, 30719);
	while (size > 0)
	{
		write(1, buf, size);
		size = read(file, buf, 30719);
	}
	if (size == -1)
	{
		print_error(filepath, program_name);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*program_name;

	program_name = argv[0];
	if (argc < 2)
	{
		ft_cat_stdin();
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		ft_cat(argv[i], program_name);
		i++;
	}
	return (0);
}
