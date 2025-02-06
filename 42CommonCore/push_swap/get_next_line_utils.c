/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:01:15 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
	check if its null
*/
static char	*dest_null(char	*dest)
{
	dest = (char *)malloc(1 * sizeof(char));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

/*
	malloc and join src and dest, then free dest
*/
char	*strjoin(char *dest, char *src)
{
	char	*result;
	int		i;
	int		j;

	if (!src)
		return (NULL);
	if (!dest)
		dest = dest_null(dest);
	result = (char *)malloc((ft_strlen(src) + ft_strlen(dest) + 1)
			* sizeof(char));
	if (!result)
		return (free(dest), NULL);
	i = -1;
	j = -1;
	if (dest)
	{
		while (dest[++i])
			result[i] = dest[i];
	}
	while (src[++j])
		result[i++] = src[j];
	result[i] = '\0';
	free(dest);
	return (result);
}

/*
	check if ended with '\n'
*/
int	charset(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
