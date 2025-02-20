/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:45:57 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/18 18:01:19 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	delimit_retoken(t_list **next, char *start)
// Adds a new node to the list of tokens before 'next', containing
// the string at 'start'
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(start));
	ft_lstadd_front(next, new);
}

void	retokenise(t_list *token)
// Retokenises the line after any unquoted spaces are added by expansions
{
	t_list	*current;
	int		i;
	char	*line;
	int		quoting;
	char	q_char;

	current = token;
	line = (char *)current->content;
	i = ft_strlen(line);
	quoting = 0;
	q_char = 0;
	while (--i >= 0)
	{
		if (apply_quoting_tokenise(&quoting, &line, &i, &q_char))
			;
		else if (ft_iswhitespace(line[i]))
		{
			line[i] = 0;
			if (line[i + 1] != 0)
				delimit_retoken(&token->next, &line[i + 1]);
		}
	}
}

void	expand_token_list(t_list *tokens, t_prog *term)
// Expands any shell variables or wildcards in an existing list of tokens
{
	t_list	*current;

	current = tokens;
	while (current != NULL)
	{
		if (*(char *)current->content == RD_HRD)
		{
			if (current->next == NULL)
				return ;
			current = current->next->next;
			continue ;
		}
		expand_token_tilde((char **)&current->content, term);
		expand_token_var((char **)&current->content, term);
		retokenise(current);
		expand_wildcards((char **)&current->content, term);
		retokenise(current);
		current = current->next;
	}
}
