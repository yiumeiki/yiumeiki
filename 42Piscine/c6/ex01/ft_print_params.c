/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:01:08 by myiu              #+#    #+#             */
/*   Updated: 2024/07/08 10:38:44 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	length;

	i = 1;
	while (argc > i)
	{
		length = 0;
		while (argv[i][length] != '\0')
		{
			write(1, &argv[i][length], 1);
			length++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
