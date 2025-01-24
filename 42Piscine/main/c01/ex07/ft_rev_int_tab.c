/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:46:16 by myiu              #+#    #+#             */
/*   Updated: 2024/07/04 15:38:11 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	x;

	i = 0;
	while (i < size / 2)
	{
		x = tab[i];
		tab[i] = tab[size -1 -i];
		tab[size -1 -i] = x;
		i++;
	}
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};
	int	size;

	size = 5;
	ft_rev_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d\n",tab[0], tab[1], tab[2], tab[3], tab[4]);
	return (0);
}
