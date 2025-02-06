/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 18:57:55 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	calculate size of tab array
*/
static int	tab_size(char **params)
{
	int	i;

	i = 0;
	if (params)
	{
		while (params[i])
			i++;
	}
	return (i);
}

/*
	reallocates memory to create a new array 
	that will hold both the strings from old and new
*/
static char	**ft_realloc(char **old, char **new)
{
	char	**add;
	int		size_old;
	int		size_new;

	size_old = tab_size(old);
	size_new = tab_size(new);
	add = ft_calloc(size_old + size_new + 1, sizeof(char *));
	if (!add)
		return (0);
	return (add);
}

/*
	It Copies the str from the "old" into the new allocated "add". 
	If allocation fails, it frees the memory (old&new), calls handle_error.
	After copying, it frees the memory used by old. It then returns the "add".
*/
static char	**add_old(char **add, char **old, char **new)
{
	int	i;

	i = -1;
	if (old)
	{
		while (old[++i])
		{
			add[i] = ft_strdup(old[i]);
			if (!add[i])
			{
				free_args(old);
				free_args(new);
				handle_error(add);
			}
		}
		free_args(old);
	}
	return (add);
}

/*
	First reallocates memory for the "add" by combining "old" and "new". 
	It then copies the str from the "old" to "add" using "add_old".
	Appends the str from the new array to "add". 
	Once all str have been copied, it frees the new array and returns "add".
*/
static char	**add_params(char **old, char **new)
{
	char	**add;
	int		i;
	int		j;

	add = ft_realloc(old, new);
	if (!add)
		handle_error(old);
	add = add_old(add, old, new);
	j = -1;
	i = 0;
	while (add[i])
		i++;
	while (new[++j])
	{
		add[i] = ft_strdup(new[j]);
		i++;
	}
	free_args(new);
	return (add);
}

/*
It uses ft_split and adds argv to the "add" array.
Splits the string into words and appends them to the "add" using "add_params"
returns the new array (add) containing all the words from the input.
*/
char	**set_input(char **av)
{
	int		i;
	char	**split;
	char	**add;

	i = 0;
	add = 0;
	if (!av[0])
		return (0);
	if (!av[0][0])
		handle_error(0);
	split = ft_split(av[0], ' ');
	if (!split || !split[0])
		handle_error(split);
	add = add_params(0, split);
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
		{
			free_args(split);
			handle_error(add);
		}
		add = add_params(add, split);
	}
	return (add);
}
