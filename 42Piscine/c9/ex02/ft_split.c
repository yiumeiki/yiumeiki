/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:36:24 by myiu              #+#    #+#             */
/*   Updated: 2024/07/15 11:01:06 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_separator(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		if (str[i] && !ft_is_separator(str[i], charset))
		{
			while (str[i] && !ft_is_separator(str[i], charset))
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_is_separator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && ft_is_separator(*str, charset))
			str++;
		if (*str && !ft_is_separator(*str, charset))
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			while (*str && !ft_is_separator(*str, charset))
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}
/*
int        main(int ac, char **av)
{
	(void)ac;
	char **tab;
	int i;
	
	i = 0;
	tab = 0;
	tab = ft_split(av[1], av[2]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
