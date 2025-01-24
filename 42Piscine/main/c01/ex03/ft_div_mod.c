/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:43:56 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 11:03:20 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	di;
	int	mo;

	di = a / b;
	mo = a % b;
	div = &di;
	mod = &mo;
	printf("%d, %d\n", *div, *mod);
}

int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 6;
	b = 2;
	div = NULL;
	mod = NULL;
	ft_div_mod(a, b, div, mod);
	return (0);
}
