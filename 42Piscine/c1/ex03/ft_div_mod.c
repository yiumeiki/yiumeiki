/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:43:56 by myiu              #+#    #+#             */
/*   Updated: 2024/07/19 12:34:48 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{

	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 6;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d\n", div, mod);
	return (0);
}
