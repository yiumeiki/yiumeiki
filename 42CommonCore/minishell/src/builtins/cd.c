/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:20:50 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:06:43 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_wd(t_prog *term, t_cmd *cmd, int revert)
// Updates data about the current working directory
// - the $PWD and $OLDPWD environment variables
// - the cwd field of the t_prog struct
{
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = (t_env *)getenv_node(term->env_list, "PWD")->content;
	if (pwd == NULL)
		pwd->var = ft_strdup(term->cwd);
	oldpwd = (t_env *)getenv_node(term->env_list, "OLDPWD")->content;
	free(oldpwd->var);
	oldpwd->var = pwd->var;
	getcwd(term->cwd, PATH_MAX);
	pwd->var = ft_strdup(term->cwd);
	if (revert == 1)
		ft_putendl_fd(term->cwd, cmd->fd_out);
	term->status = 0;
}

static char	*get_path(t_prog *term, char **argv, int *revert)
// Gets the path used to change directory.
// Sets the 'revert' variable used to determine printing directory for "cd -"
{
	char	*path;

	*revert = 0;
	if (argv[1] == NULL || ft_strncmp(argv[1], "--", 3) == 0)
		path = getenv_list(term->env_list, "HOME");
	else if (ft_strncmp(argv[1], "-", 2) == 0)
	{
		*revert = 1;
		path = getenv_list(term->env_list, "OLDPWD");
	}
	else
		path = argv[1];
	if (path == NULL)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		if (*revert == 1)
			ft_putstr_fd("OLDPWD", 2);
		else
			ft_putstr_fd("HOME", 2);
		ft_putendl_fd(" not set", 2);
	}
	return (path);
}

void	cd(t_prog *term, t_cmd *cmd, t_list *pipeline)
// Executes the 'cd' builtin command
{
	char	*path;
	int		revert;

	path = get_path(term, cmd->argv, &revert);
	if (path == NULL)
		term->status = 1 << 8;
	else if (cmd->argc > 2)
	{
		ft_putendl_fd("\e[32mminishell: \e[35mcd: \e[mtoo many arguments", 2);
		term->status = 1 << 8;
	}
	else if (ft_lstsize(pipeline) > 1)
	{
		if (revert == 1)
			ft_putendl_fd(getenv_list(term->env_list, "OLDPWD"), cmd->fd_out);
	}
	else if (chdir(path) != 0)
	{
		ft_putstr_fd("\e[32mminishell: \e[35mcd: \e[m", 2);
		ft_putendl_fd(strerror(errno), 2);
		term->status = 1 << 8;
	}
	else
		update_wd(term, cmd, revert);
}
