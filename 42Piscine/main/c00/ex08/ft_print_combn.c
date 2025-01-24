/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:51:53 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 15:13:06 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdio.h> 

void	ft_putchar(char a, char b)
{
	write(1, &a, 1);
	write(1, &b, 1);
	if (!(a == '8' && b == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	m;

	n = 0;
	while (n <= 9)
	{
		m = n + 1;
		while (m <= 9)
		{
			if (n != m && n < m)
			{
				ft_putchar(n + 48, m + 48);
			}
			m++;
		}
		n++;
	}
}

int	main(void)
{
	int	n;

	n = 3;
	ft_print_combn(n);
}
