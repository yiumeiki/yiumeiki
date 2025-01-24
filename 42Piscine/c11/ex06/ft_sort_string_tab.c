/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:54:54 by myiu              #+#    #+#             */
/*   Updated: 2024/07/16 16:02:42 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	index;
	int	i;

	i = 0;
	while (tab[i])
	{
		index = 0;
		while (tab[index])
		{
			if (tab[index + 1] && ft_strcmp(tab[index], tab[index + 1]) > 0)
				ft_swap(&tab[index], &tab[index + 1]);
			index++;
		}
		i++;
	}
}
/*
#include <string.h>
#include <stdio.h>
int		main(void)
{
	int		i;
	char	**tab;

	tab = malloc(6 * sizeof(char *));
	tab[0] = strdup("m");
	tab[1] = strdup("e");
	tab[2] = strdup("i");
	tab[3] = strdup("5");
	tab[4] = strdup("1");
	tab[5] = strdup("8");
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] <@ %p> = $%s$\n", i, tab + i, tab[i]);
		i++;
	}
	ft_sort_string_tab(tab);
	printf("\n");
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] <@ %p> = $%s$\n", i, tab + i, tab[i]);
		i++;
	}
}*/
