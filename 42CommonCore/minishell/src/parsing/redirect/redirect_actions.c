/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:04:38 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:45:54 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	init_rd_out(int *fd, int *fmode, int mode)
{
	*fd = -2;
	*fmode = O_WRONLY | O_CREAT;
	if (mode == RD_APP)
		*fmode |= O_APPEND;
	else
		*fmode |= O_TRUNC;
}

void	redirect_out(t_cmd *cmd, t_list **rd_token, t_list *prev, int mode)
// Applies file redirection for the redirect out (>) or append (>>) operator.
// Trims redirection tokens from the token list.
{
	int		fd;
	int		fmode;

	init_rd_out(&fd, &fmode, mode);
	if ((*rd_token)->next != NULL)
		fd = open((char *)(*rd_token)->next->content, fmode, 0644);
	else
	{
		ft_dprintf(2, "minishell: ambiguous redirect");
		cmd->rd_err = 1;
	}
	if (fd == -1)
	{
		ft_dprintf(2, "minishell: %s: No such file or directory",
			(char *)(*rd_token)->next->content);
		cmd->rd_err = 1;
	}
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	cmd->fd_out = fd;
	cmd->rd_out = 1;
	ft_lstdel_next(prev, free);
	if (fd != -2)
		ft_lstdel_next(prev, free);
	*rd_token = NULL;
}

void	open_rd_in(int *fd, t_cmd *cmd, t_list **rd_token)
{
	*fd = open((char *)(*rd_token)->next->content, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((char *)(*rd_token)->next->content, 2);
		ft_putendl_fd(": No such file or directory", 2);
		cmd->rd_err = 1;
	}
}

void	redirect_in(t_cmd *cmd, t_list **rd_token, t_list *prev)
// Applies file redirection for the redirect in (<) operator.
// Trims redirection tokens from the token list.
{
	int		fd;

	fd = -1;
	if ((*rd_token)->next != NULL)
		open_rd_in(&fd, cmd, rd_token);
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putendl_fd("ambiguous redirect", 2);
		cmd->rd_err = 1;
	}
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	cmd->fd_in = fd;
	cmd->rd_in = 1;
	ft_lstdel_next(prev, free);
	if (fd != -2)
		ft_lstdel_next(prev, free);
	*rd_token = NULL;
}

void	redirect_hdoc(t_cmd *cmd, t_list **rd_token, t_list *prev)
// Applies file redirection for the heredoc (<<) operator.
// Trims redirection tokens from the token list.
{
	if (cmd->fd_in > 2 && cmd->fd_in != cmd->hdpipe[0])
		close(cmd->fd_in);
	cmd->fd_in = cmd->hdpipe[0];
	ft_lstdel_next(prev, free);
	*rd_token = NULL;
}
