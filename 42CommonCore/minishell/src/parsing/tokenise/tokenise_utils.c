/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:53:59 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/08 17:00:57 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	is_op(char c)
// Checks if a character can form part of an operator.
{
	if (ft_strchr("><|&()", c) == NULL)
		return (0);
	return (1);
}

int	token_is_op(t_list *token)
{
	if (token == NULL)
		return (3);
	else if (ft_strchr("()", *(char *)token->content))
		return (2);
	else if (ft_strchr("><", *(char *)token->content))
		return (1);
	else if (ft_strchr("|&", *(char *)token->content))
		return (4);
	return (0);
}

int	matches_prev_op(char c, char prev)
// Checks if a character can be used with the previous character to
// form an operator.
{
	if (prev == '<' && c == '<')
		return (1);
	else if (prev == '>' && c == '>')
		return (1);
	else if (prev == '|' && c == '|')
		return (1);
	else if (prev == '&' && c == '&')
		return (1);
	return (0);
}

void	print_tokens(t_list *tokens)
// Prints a list of tokens for debugging purposes.
{
	t_list	*current;

	current = tokens;
	while (current != NULL)
	{
		if (*(char *)current->content == RD_IN)
			ft_printf("token:\t\e[7;35mRD_IN  <\e[m\n");
		else if (*(char *)current->content == RD_OUT)
			ft_printf("token:\t\e[7;32mRD_OUT >\e[m\n");
		else if (*(char *)current->content == RD_APP)
			ft_printf("token:\t\e[7;36mRD_APP >>\e[m\n");
		else if (*(char *)current->content == RD_HRD)
			ft_printf("token:\t\e[7;31mRD_HRD <<\e[m\n");
		else
			ft_printf("token:\t<%s>\n", (char *)current->content);
		current = current->next;
	}
}
