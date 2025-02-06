/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 18:01:23 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	free stack
	if int quit == 1, no need free(sorted so no malloc)
*/
void	free_stack(t_stack **stack, char **args, int quit)
{
	t_stack	*tmp;

	free_args(args);
	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
		*stack = 0;
	}
	if (quit)
		exit(0);
}

/*
	free "tab" array containing numbers from argv
*/
void	free_args(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
		tab = 0;
	}
}

/*
	Handle error: free and print, then exit
*/
void	handle_error(char **tab)
{
	free_args(tab);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
