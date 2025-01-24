/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:08:38 by myiu              #+#    #+#             */
/*   Updated: 2024/07/08 17:05:23 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (src[i] != '\0')
	{
		length++;
		i++;
	}
	copy = (char *)malloc(length + 1);
	if (copy != NULL)
	{
		i = 0;
		while (src[i] != '\0')
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}
/*
int main(){
	char src[] = "jomei";
	char *copy = ft_strdup(src);
	if (copy != NULL)
	{
		printf("%s\n", copy);
		free(copy);
	}
}*/
