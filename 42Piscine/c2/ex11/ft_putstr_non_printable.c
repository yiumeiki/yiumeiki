/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:04:52 by myiu              #+#    #+#             */
/*   Updated: 2024/07/07 11:31:37 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hexa(int c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c < 0)
	{
		c += 256;
	}
	if (c >= 16)
	{
		ft_put_hexa(c / 16);
		ft_put_hexa(c % 16);
	}
	else
	{
		if (c < 16)
			ft_putchar('0');
		ft_putchar(base[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			j = str[i];
			ft_put_hexa(j);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
