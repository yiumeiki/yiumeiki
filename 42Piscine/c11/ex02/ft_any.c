/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:53:36 by myiu              #+#    #+#             */
/*   Updated: 2024/07/15 19:34:05 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int ft(char *str)
{
	if (*str == 'A')
		return (1);
	return (0);
}
int main (void)
{
	char	**tab;
	int	i;

	i = 0;
	tab = malloc(3 * sizeof(char *));
	tab[0] = "A";
	tab[1] = "Z";
	tab[2] = NULL;
	while (i < 3)
	{
		printf("%d\n", ft_any(&tab[i], ft));
		i++;
	}
}*/
