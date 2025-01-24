/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:16 by myiu              #+#    #+#             */
/*   Updated: 2024/07/07 16:08:12 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int len, char begin_char, char mid_char, char end_char)
{
	int	letter_counter;

	letter_counter = 0;
	while (letter_counter < len)
	{
		if (letter_counter == 0)
			ft_putchar(begin_char);
		else if (letter_counter == (len - 1))
			ft_putchar(end_char);
		else
			ft_putchar(mid_char);
		letter_counter++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	line_counter;

	line_counter = 0;
	if (x >= 1 && y >= 1)
	{
		while (line_counter < y)
		{
			if (line_counter == 0)
				ft_print(x, 'A', 'B', 'C');
			else if (line_counter == (y - 1))
				ft_print(x, 'C', 'B', 'A');
			else
				ft_print(x, 'B', ' ', 'B');
			line_counter++;
		}
	}
}
