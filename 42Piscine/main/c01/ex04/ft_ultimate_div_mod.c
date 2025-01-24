/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:06:12 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 11:12:16 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = c / *b;
	*b = c % *a;
	printf("%d, %d\n", *a, *b);
}

int	main(void)
{
	int	x;
	int	y;
	int	*a;
	int	*b;

	x = 6;
	y = 2;
	a = &x;
	b = &y;
	ft_ultimate_div_mod(a, b);
	return (0);
}
