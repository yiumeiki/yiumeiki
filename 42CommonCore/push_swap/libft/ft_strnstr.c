/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/01 18:22:41 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	llen;

	if (!big && len == 0)
		return (NULL);
	llen = ft_strlen(little);
	if (llen == 0)
		return ((char *)big);
	count = 0;
	while (*big && count < len)
	{
		if ((ft_strncmp((char *)big, (char *)little, llen) == 0)
			&& count + llen <= len)
		{
			return ((char *)big);
		}
		big++;
		count++;
	}
	return (0);
}
