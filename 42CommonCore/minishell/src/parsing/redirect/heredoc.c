/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:06 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:45:54 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	write_hdoc(t_cmd *cmd, t_list *hdoc, t_prog *term, int expand)
// Writes text input collected by the heredoc into the heredoc pipe,
// to be later read from by a command.
{
	t_list	*current;
	char	*var;

	current = hdoc;
	while (current != NULL)
	{
		if (expand)
		{
			var = ft_strchr((char *)current->content, '$');
			while (var != NULL)
			{
				expand_var_inplace((char **)&current->content, var, term, 0);
				var = ft_strchr((char *)current->content, '$');
			}
		}
		ft_putendl_fd((char *)current->content, cmd->hdpipe[1]);
		current = current->next;
	}
}

void	handle_hdoc_child(t_cmd *cmd, t_prog *term, char *delim, int expand)
{
	char				*line;
	t_list				*hdoc;

	hdoc = NULL;
	signal(SIGINT, hdoc_handler);
	line = get_input_line(term, 1);
	hdoc_check_sig(cmd, term, &hdoc, line);
	while (line != NULL && ft_strncmp(line, delim, ft_strlen(delim) + 1))
		collect_hdoc_line(&hdoc, &line, cmd, term);
	if (line == NULL)
	{
		ft_putstr_fd("minishell: warning: here-document ", 2);
		ft_putstr_fd("delimited by end-of-file (wanted `", 2);
		ft_putstr_fd(delim, 2);
		ft_putendl_fd("')", 2);
	}
	else
	{
		free(line);
		line = NULL;
	}
	write_hdoc(cmd, hdoc, term, expand);
	cleanup_heredoc(&hdoc, cmd, term, line);
	exit(0);
}

void	read_hdoc(t_cmd *cmd, char *delim, t_prog *term, int expand)
{
	pid_t				pid;

	if (cmd->hdpipe[0] > 2)
		close(cmd->hdpipe[0]);
	pipe(cmd->hdpipe);
	pid = fork();
	if (pid == 0)
		handle_hdoc_child(cmd, term, delim, expand);
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &term->parse_status, 0);
		setup_signals();
	}
	return ;
}

void	process_hdoc(t_cmd *cmd, t_list *rd_token, t_prog *term)
{
	char	*delim;
	int		expand;

	expand = 1;
	delim = (char *)rd_token->next->content;
	if (ft_strchr(delim, '\"') || ft_strchr(delim, '\''))
	{
		expand = 0;
		strip_quotes_token(delim);
	}
	read_hdoc(cmd, delim, term, expand);
	cmd->rd_in = 1;
	close(cmd->hdpipe[1]);
	if (term->parse_status > 0)
	{
		if (is_debug(term))
			ft_printf("\e[31m### HDOC FAILED ###\e[m\n");
	}
	ft_lstdel_next(rd_token, free);
}

void	handle_hdocs(t_cmd *cmd, t_prog *term)
{
	t_list	*current;
	int		mode;

	current = cmd->tokens;
	while (current != NULL && term->parse_status == 0)
	{
		mode = *(char *)current->content;
		if (mode == RD_HRD)
			process_hdoc(cmd, current, term);
		current = current->next;
	}
}
