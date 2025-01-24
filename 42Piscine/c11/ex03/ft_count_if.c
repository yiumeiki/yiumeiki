/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:27:19 by myiu              #+#    #+#             */
/*   Updated: 2024/07/15 19:46:44 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>
int	ft(char *str)
{
	if (*str == 'A')
		return (1);
	return (0);
}

int main (void)
{
	char	**tab;

	tab = malloc(4 * sizeof(char *));
	tab[0] = "A";
	tab[1] = "Z";
	tab[2] = "A";
	tab[3] = "NULL";
	printf("%d\n", ft_count_if(tab, 3, ft));
}*/
