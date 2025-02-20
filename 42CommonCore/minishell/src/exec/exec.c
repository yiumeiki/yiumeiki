/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:39:24 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:06:17 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/parsing.h"

void	handle_search_fail(int search, t_cmd *cmd, t_prog *term)
{
	if (search == 1)
	{
		term->status = 127 << 8;
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
	else if (search == 2)
	{
		term->status = 126 << 8;
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putendl_fd(": Permission denied", 2);
	}
}

pid_t	exec_cmd(t_prog *term, t_cmd *cmd, t_list *pipeline, t_list *cur_cmd)
{
	pid_t	child;
	char	cmd_path[PATH_MAX];
	int		search;

	child = -1;
	if (cmd->rd_err > 0)
		term->status = 1 << 8;
	else if (!handle_builtins(term, cmd, pipeline))
	{
		search = search_path(term, (cmd->argv)[0], cmd_path);
		if (search == 0)
		{
			child = fork();
			if (child == 0)
				handle_child(cmd, term, cur_cmd, cmd_path);
		}
		else
			handle_search_fail(search, cmd, term);
	}
	return (child);
}

void	wait_for_pipeline(t_ptree *treenode, t_prog *term, int status)
{
	t_list	*current;

	current = treenode->pids;
	signal(SIGINT, SIG_IGN);
	while (current != NULL)
	{
		if (*(pid_t *)current->content != -1)
			waitpid(*(pid_t *)current->content, &term->status, 0);
		else
			term->status = status;
		current = current->next;
	}
	setup_signals();
	ft_lstclear(&treenode->pids, free);
}

void	execute_pipeline(t_ptree *treenode, t_prog *term)
{
	t_list	*current;
	t_cmd	*cmd;
	pid_t	*child;
	int		status;

	current = treenode->pipeline;
	while (current != NULL)
	{
		cmd = (t_cmd *)current->content;
		child = ft_calloc(1, sizeof(pid_t));
		ft_lstadd_back(&treenode->pids, ft_lstnew(child));
		*child = exec_cmd(term, cmd, treenode->pipeline, current);
		free_cmd(current->content);
		current->content = NULL;
		if (*child == -1)
			status = term->status;
		current = current->next;
	}
	wait_for_pipeline(treenode, term, status);
}

void	handle_exit_sig(t_prog *term);

void	execute_ptree(t_ptree *ptree, t_prog *term)
{
	if (ptree == NULL)
		return ;
	if (term->parse_status != 0)
		return ;
	execute_ptree(ptree->left, term);
	if (ptree->op == 0)
	{
		parse_pipeline(ptree, term);
		connect_pipes(ptree->pipeline);
		if (term->parse_status == 0)
		{
			execute_pipeline(ptree, term);
			handle_exit_sig(term);
		}
	}
	else if (ptree->op == OP_AND && term->status != 0)
		return ;
	else if (ptree->op == OP_OR && term->status == 0)
		return ;
	execute_ptree(ptree->right, term);
}
