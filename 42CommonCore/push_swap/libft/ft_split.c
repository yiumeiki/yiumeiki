/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/01 18:22:13 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**malloc_free(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	*malloc_word(char *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (j < i)
	{
		word[j++] = (char)*s++;
	}
	word[j] = '\0';
	return (word);
}

static char	**insert_words(char **words, char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (char)*s == c)
			s++;
		if (*s && (char)*s != c)
		{
			words[i] = malloc_word(s, c);
			if (!words[i])
				return (malloc_free(words));
			i++;
		}
		while (*s && (char)*s != c)
			s++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = count_words((char *)s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = insert_words(split, (char *)s, c);
	return (split);
}
