/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:38:00 by myiu              #+#    #+#             */
/*   Updated: 2024/07/25 19:06:18 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	strlen_decide_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	num;

	num = nbr;
	len = strlen_decide_base(base);
	if (len == 0)
		return ;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= len)
	{
		ft_putnbr_base(num / len, base);
		ft_putnbr_base(num % len, base);
	}
	else
		ft_putchar(base[num]);
}
