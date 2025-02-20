/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:32 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:40:29 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

extern sig_atomic_t	g_signal;

void	cleanup_heredoc(t_list **hdoc, t_cmd *cmd, t_prog *term, char *line)
{
	ft_lstclear(hdoc, free);
	if (line)
		free(line);
	close(cmd->hdpipe[0]);
	close(cmd->hdpipe[1]);
	traverse_ptree(term->ptree, PST_ORD, free_ptree_node, NULL);
	free(term->line);
	cleanup(term);
}

void	hdoc_check_sig(t_cmd *cmd, t_prog *term, t_list **hdoc, char *line)
{
	if (g_signal == SIGINT)
	{
		cleanup_heredoc(hdoc, cmd, term, line);
		exit(1);
	}
}

void	collect_hdoc_line(t_list **hdoc, char **line, t_cmd *cmd, t_prog *term)
{
	ft_lstadd_back(hdoc, ft_lstnew(*line));
	*line = get_input_line(term, 1);
	hdoc_check_sig(cmd, term, hdoc, *line);
}
