/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:09:34 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 10:21:35 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	br;
	int	*a1;
	int	**a2;
	int	***a3;
	int	****a4;
	int	*****a5;
	int	******a6;
	int	*******a7;
	int	********a8;
	int	*********nbr;

	br = 88;
	a2 = &a1;
	a3 = &a2;
	a4 = &a3;
	a5 = &a4;
	a6 = &a5;
	a7 = &a6;
	a8 = &a7;
	a1 = &br;
	nbr = &a8;
	ft_ultimate_ft(nbr);
	printf("%d\n", br);
	return (0);
}
