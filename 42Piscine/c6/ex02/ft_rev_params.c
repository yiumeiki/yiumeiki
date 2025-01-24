/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:39:26 by myiu              #+#    #+#             */
/*   Updated: 2024/07/08 10:47:37 by myiu             ###   ########.fr       */
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
		while (argv[argc - i][length] != '\0')
		{
			write(1, &argv[argc - i][length], 1);
			length++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
