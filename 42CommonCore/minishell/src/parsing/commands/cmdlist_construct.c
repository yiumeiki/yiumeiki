/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist_construct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:55:53 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:59:21 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_cmd	*construct_cmd(t_list *tokens);

int	push_cmd_sep(t_list **current_tkn, t_list **temp,
					t_list **ptree_list, int init)
{
	t_cmd	*cmd;

	if (!init)
		(*temp)->next = NULL;
	while (is_cmd_sep(*current_tkn) > OP_PIPE)
	{
		push_ptree_stack(ptree_list,
			ptree_new(NULL, is_cmd_sep(*current_tkn)));
		*temp = *current_tkn;
		*current_tkn = (*current_tkn)->next;
		ft_lstdelone(*temp, free);
		if (*current_tkn == NULL)
			break ;
	}
	if (init)
		return (1);
	if (*current_tkn == NULL)
		return (0);
	cmd = construct_cmd(*current_tkn);
	push_ptree_stack(ptree_list, ptree_new(ft_lstnew(cmd), 0));
	return (1);
}

void	push_pipe(t_list **current_tkn, t_list **pipeline)
{
	t_cmd	*cmd;

	cmd = construct_cmd((*current_tkn)->next);
	ft_lstadd_back(pipeline, ft_lstnew(cmd));
	(*current_tkn)->next = NULL;
	(*current_tkn) = cmd->tokens;
}

void	init_pipeline(t_list **pipeline, t_list **ptree_list,
						t_list *current_tkn)
{
	t_cmd	*cmd;

	cmd = construct_cmd(current_tkn);
	ft_lstadd_back(pipeline, ft_lstnew(cmd));
	push_ptree_stack(ptree_list, ptree_new(*pipeline, 0));
}

t_list	*split_commands(t_list *tokens)
{
	t_list	*pipeline;
	t_list	*ptree_list;
	t_list	*current_tkn;
	t_list	*temp;

	ptree_list = NULL;
	pipeline = NULL;
	current_tkn = tokens;
	temp = NULL;
	push_cmd_sep(&current_tkn, &temp, &ptree_list, 1);
	init_pipeline(&pipeline, &ptree_list, current_tkn);
	while (current_tkn != NULL)
	{
		if (is_cmd_sep(current_tkn) == OP_PIPE && current_tkn->next != NULL)
			push_pipe(&current_tkn, &pipeline);
		else if (is_cmd_sep(current_tkn) > OP_PIPE)
		{
			if (!push_cmd_sep(&current_tkn, &temp, &ptree_list, 0))
				break ;
			pipeline = ((t_ptree *)ft_lstlast(ptree_list)->content)->pipeline;
		}
		temp = current_tkn;
		current_tkn = current_tkn->next;
	}
	return (ptree_list);
}
