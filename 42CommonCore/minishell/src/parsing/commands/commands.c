/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:36 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:58:57 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_cmd	*construct_cmd(t_list *tokens)
// Returns a memory allocated t_cmd struct containing 'tokens'.
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->tokens = tokens;
	cmd->fd_out = 1;
	(cmd->pipe)[0] = -1;
	(cmd->pipe)[1] = -1;
	(cmd->hdpipe)[0] = -1;
	(cmd->hdpipe)[1] = -1;
	cmd->sep = OP_NONE;
	return (cmd);
}

int	is_cmd_sep(t_list *token)
// Checks if a token is used to separate commands.
{
	char	*text;

	text = (char *)token->content;
	if (*text == OP_PIPE)
		return (OP_PIPE);
	if (ft_strncmp(text, "||", 3) == 0)
		return (OP_OR);
	if (ft_strncmp(text, "&&", 3) == 0)
		return (OP_AND);
	if (ft_strncmp(text, "(", 2) == 0)
		return (OP_OPNPRN);
	if (ft_strncmp(text, ")", 2) == 0)
		return (OP_CLSPRN);
	return (0);
}

void	free_cmd(void *cmdptr)
// Frees a t_cmd struct.
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmdptr;
	if (cmd == NULL)
		return ;
	ft_lstclear(&cmd->tokens, free);
	free(cmd->argv);
	if (cmd->rd_in == 1 && cmd->fd_in > 0)
		close(cmd->fd_in);
	if (cmd->rd_out == 1 && cmd->fd_out > 0)
		close(cmd->fd_out);
	if ((cmd->pipe)[0] > 0)
	{
		close((cmd->pipe)[1]);
		close((cmd->pipe)[0]);
	}
	free(cmdptr);
}

void	free_pipeline(void *lstptr)
{
	t_list	*pipeline;

	pipeline = (t_list *)lstptr;
	ft_lstclear(&pipeline, free_cmd);
}
