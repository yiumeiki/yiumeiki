/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:13:41 by myiu              #+#    #+#             */
/*   Updated: 2024/08/25 16:13:42 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	i += 1;
	result = (char *)malloc(i * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (j < i)
	{
		result[j] = s[j];
		j++;
	}
	return (result);
}
