/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:38:03 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/06 16:32:45 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	encode_pipes(t_list *token)
{
	char	*text;

	text = (char *)token->content;
	if (ft_strncmp(text, "|", 2) != 0)
		return ;
	free(token->content);
	token->content = ft_strdup(" ");
	*(char *)token->content = OP_PIPE;
}

void	connect_pipes(t_list *pipeline)
// Loops over a list of pipelines. For each pieline loops over 
// each command and connects any necessary pipes.
{
	t_cmd	*current;
	t_cmd	*next;
	t_list	*current_cmd;

	current_cmd = pipeline;
	while (current_cmd->next != NULL)
	{
		current = (t_cmd *)current_cmd->content;
		next = (t_cmd *)current_cmd->next->content;
		// if (current->sep == OP_PIPE)
		// {
		pipe(next->pipe);
		if (current->fd_out == 1)
			current->fd_out = (next->pipe)[1];
		if (next->fd_in == 0)
			next->fd_in = (next->pipe)[0];
		// }
		current_cmd = current_cmd->next;
	}
}
