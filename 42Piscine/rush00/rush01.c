/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:05:56 by myiu              #+#    #+#             */
/*   Updated: 2024/07/07 17:02:03 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	c;
	int	r;

	r = 0;
	while (r < y)
		c = 0;
	while (c < x)
	{
		if ((r == 0 && c == 0) || ((r == (y - 1) && c == (x - 1)
					&& (r != 0 && c != 0))))
			ft_putchar('/');
		else if ((r == 0 && c == (x - 1) || r == (y - 1) && c == 0))
			ft_putchar('\\');
		else if ((c > 0 && c < (x - 1) && r == 0) || ((c > 0 && c < (x - 1)
					&& r == (y - 1))))
			ft_putchar('*');
		else if ((c == 0 && r > 0 && r < (y - 1)) || ((c == (x - 1) && r > 0
					&& r < (y - 1))))
			ft_putchar('*');
		else
			ft_putchar(' ');
		c++;
	}
	ft_putchar('\n');
	r++;
}
