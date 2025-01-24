/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:14:12 by jkaucky           #+#    #+#             */
/*   Updated: 2024/07/24 17:32:19 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Added null terminator clause
int	in_cs(char c, char *charset)
{
	int	inc;

	inc = 0;
	while (charset[inc] != '\0')
	{
		if (c - charset[inc] == 0)
			return (1);
		inc++;
	}
	return (0);
}

char	**str_arr_malloc(char *str, char *charset)
{
	char	*cs;
	char	**str_arr;
	int		i;
	int		str_count;

	cs = charset;
	i = 0;
	str_count = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || in_cs(str[i - 1], cs)) && !(in_cs(str[i], cs)))
			str_count++;
		i++;
	}
	str_arr = malloc((str_count + 1) * 8);
	i = 0;
	while (i < str_count)
	{
		str_arr[i] = " ";
		i++;
	}
	str_arr[str_count] = 0;
	return (str_arr);
}

char	*find_fill_substr(char *str, int start, int end)
{
	char	*substring;
	int		i;
	int		len;

	len = end - start;
	substring = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		substring[i] = str[start + i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	char	*cs;
	int		i;
	int		temp_inc;
	int		arr_inc;

	cs = charset;
	str_arr = str_arr_malloc(str, cs);
	i = 0;
	arr_inc = 0;
	while (str_arr[arr_inc] != 0)
	{
		if ((i == 0 || in_cs(str[i - 1], cs))
			&& !(in_cs(str[i], cs)) && str[i] != '\0')
		{
			temp_inc = i;
			while (str[i] != '\0' && !(in_cs(str[i], cs)))
				i++;
			str_arr[arr_inc] = find_fill_substr(str, temp_inc, i);
			arr_inc++;
		}
		else
			i++;
	}
	return (str_arr);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	last_diff;

	i = 0;
	last_diff = -1;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			last_diff = i;
		i++;
	}
	return (last_diff);
}
