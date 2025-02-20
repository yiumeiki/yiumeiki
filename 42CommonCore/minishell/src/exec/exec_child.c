/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:31:19 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:06:33 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtins/builtins.h"

int	handle_builtins(t_prog *term, t_cmd *cmd, t_list *pipeline)
// Checks if a given command is a builtin, and if so executes it.
// Returns 1 if command was a builtin
// Returns 0 if command was not a builtin
{
	if (cmd->argv[0] == NULL || (*cmd->argv[0] == 0 && cmd->stripped == 0))
	// if (cmd->argv[0] == NULL)
	{
		term->status = 0;
		return (1);
	}
	if (!ft_strncmp((cmd->argv)[0], "cd", 3))
		cd(term, cmd, pipeline);
	else if (!ft_strncmp((cmd->argv)[0], "pwd", 4))
		pwd(term, cmd);
	else if (!ft_strncmp((cmd->argv)[0], "env", 4))
		env(term, cmd, construct_envp(term->env_list));
	else if (!ft_strncmp((cmd->argv)[0], "export", 7))
		export_env(term, cmd, pipeline);
	else if (!ft_strncmp((cmd->argv)[0], "unset", 6))
		unset_env(term, cmd);
	else if (!ft_strncmp((cmd->argv)[0], "echo", 5))
		echo(term, cmd);
	else if (!ft_strncmp((cmd->argv)[0], "exit", 5))
		exit_shell(term, cmd);
	else
		return (0);
	return (1);
}

int	int_cmp(void *num1, void *num2)
{
	int	diff;
	int	nbr1;
	int	nbr2;

	nbr1 = *(int *)num1;
	nbr2 = *(int *)num2;
	diff = nbr1 - nbr2;
	return (diff);
}

t_list	*get_fds_child(t_list *pipeline)
{
	t_list	*current;
	t_cmd	*cmd;
	t_list	*fds;

	fds = NULL;
	current = pipeline;
	while (current != NULL)
	{
		cmd = (t_cmd *)current->content;
		if (cmd->fd_in > 2
			&& !ft_lst_exists(fds, &cmd->fd_in, int_cmp))
			ft_lstadd_back(&fds, ft_lstnew(&cmd->fd_in));
		if (cmd->fd_out > 2
			&& !ft_lst_exists(fds, &cmd->fd_out, int_cmp))
			ft_lstadd_back(&fds, ft_lstnew(&cmd->fd_out));
		if (cmd->pipe[0] > 2
			&& !ft_lst_exists(fds, &cmd->pipe[0], int_cmp))
			ft_lstadd_back(&fds, ft_lstnew(&cmd->pipe[0]));
		if (cmd->pipe[1] > 2
			&& !ft_lst_exists(fds, &cmd->pipe[1], int_cmp))
			ft_lstadd_back(&fds, ft_lstnew(&cmd->pipe[1]));
		current = current->next;
	}
	return (fds);
}

void	close_fds_child(t_list *pipeline)
{
	t_list	*current;
	t_list	*fds;

	fds = get_fds_child(pipeline);
	current = fds;
	while (current != NULL)
	{
		close(*(int *)current->content);
		current = current->next;
	}
	ft_lstclear(&fds, NULL);
}

void	handle_child(t_cmd *cmd, t_prog *term, t_list *pipeline, char *cmd_path)
// Branch of commands to be executed by child after fork.
// dups the appropriate file descriptors and executes the passed in command.
{
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);
	close_fds_child(pipeline);
	reset_child_sig();
	execve(cmd_path, cmd->argv, construct_envp(term->env_list));
	exit(EXIT_FAILURE);
}
