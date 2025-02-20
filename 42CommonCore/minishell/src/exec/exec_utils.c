/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:46:00 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:06:29 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/stat.h>

int	count_args(char **argv)
// Counts the number of args in an **argv.
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

static char	**init_search(t_prog *term, char *cmd,
						char *cmd_path, struct stat **statbuf)
{
	char		**paths;
	int			path_exists;

	*statbuf = ft_calloc(1, sizeof(**statbuf));
	path_exists = 1;
	if (getenv_list(term->env_list, "PATH") == NULL)
	{
		paths = ft_split("", ':');
		path_exists = 0;
	}
	else
		paths = ft_split(getenv_list(term->env_list, "PATH"), ':');
	ft_bzero(cmd_path, PATH_MAX);
	if (ft_strchr(cmd, '/') != NULL || path_exists == 0)
		ft_strlcat(cmd_path, cmd, PATH_MAX);
	stat(cmd_path, *statbuf);
	return (paths);
}

void	prepare_path(char *cmd_path, char *paths, char *cmd,
			struct stat *statbuf)
{
	ft_strlcpy(cmd_path, paths, PATH_MAX);
	ft_strlcat(cmd_path, "/", PATH_MAX);
	ft_strlcat(cmd_path, cmd, PATH_MAX);
	stat(cmd_path, statbuf);
}

int	search_path(t_prog *term, char *cmd, char *cmd_path)
// Searches the PATH variable to see if an executable matches the cmd name.
// If found, places the full command path in the cmd_path array and returns 1
// If no executable is found, cmd_path is empty and return 0
{
	struct stat	*statbuf;
	char		**paths;
	int			i;
	int			exists;

	paths = init_search(term, cmd, cmd_path, &statbuf);
	i = 0;
	while (access(cmd_path, X_OK) || !(statbuf->st_mode & S_IFREG))
	{
		exists = !access(cmd_path, F_OK);
		ft_bzero(cmd_path, PATH_MAX);
		if (paths[i] == NULL || ft_strchr(cmd, '/') != NULL)
			break ;
		prepare_path(cmd_path, paths[i++], cmd, statbuf);
	}
	free_split(&paths);
	free(statbuf);
	if (cmd_path[0] == 0)
	{
		if (!exists || *cmd == 0 || ft_strncmp(cmd, ".", 2) == 0
			|| ft_strncmp(cmd, "..", 3) == 0)
			return (1);
		return (2);
	}
	return (0);
}

void	handle_exit_sig(t_prog *term)
{
	if (WIFSIGNALED(term->status))
	{
		if (WTERMSIG(term->status) == SIGQUIT)
		{
			if (WCOREDUMP(term->status))
				ft_putendl_fd("Quit (core dumped)", 2);
			else
				ft_putendl_fd("Quit", 2);
		}
		else if (WTERMSIG(term->status) == SIGINT)
			ft_putendl_fd("", 2);
		term->status += ((128 + WTERMSIG(term->status)) << 8);
	}
}
