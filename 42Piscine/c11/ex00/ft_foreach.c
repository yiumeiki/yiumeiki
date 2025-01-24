/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:14:24 by myiu              #+#    #+#             */
/*   Updated: 2024/07/15 19:24:29 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <stdio.h>
void ft_putnbr(int nb)
{
	printf("%d\n", nb);
}

int	main()
{
	int	tab[6] = {1,2,3,4,5,6};
	int	length = 6;
	void	(*f)(int) = &ft_putnbr;
	ft_foreach(tab, length, f);

}*/
