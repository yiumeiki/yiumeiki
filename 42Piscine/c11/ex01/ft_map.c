/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:51:11 by myiu              #+#    #+#             */
/*   Updated: 2024/07/15 19:24:10 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	i = 0;
	result = malloc((4 * length));
	if (!result)
		return (NULL);
	while (length > i)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int	ft_return(int tab)
{
	tab += 2;
	return tab;
}

int main(){
	int tab[5] = {1,2,3,4,5};
	int length = 5;
	int	(*f)(int) = ft_return;
	int *result = ft_map(tab, length, f);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", result[i]);}
}*/
