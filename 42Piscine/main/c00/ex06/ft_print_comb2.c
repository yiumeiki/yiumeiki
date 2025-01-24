/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb22.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:19:28 by myiu              #+#    #+#             */
/*   Updated: 2024/07/03 19:45:08 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb22(char a, char b, char c, char d);

void	ft_d(char a, char b, char c, char d)
{
	char	x;
	char	y;
	char	w;
	char	z;

	x = a;
	y = b;
	w = c;
	z = d;
	z = '1';
	while (z <= '9')
	{
		ft_print_comb22(x, y, w, z);
		z++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				ft_d(a, b, c, d);
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb22(char x, char y, char w, char z)
{
	char	e;
	char	f;
	char	g;
	char	h;

	e = x;
	f = y;
	g = w;
	h = z;
	if ((e + f) < (g + h))
	{
		write(1, &e, 1);
		write(1, &f, 1);
		write(1, " ", 2);
		write(1, &g, 1);
		write(1, &h, 1);
		{
			if (!(e == '9' && f == '8' && g == '9' && h == '9'))
				write(1, ", ", 2);
		}
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
