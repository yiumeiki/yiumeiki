/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:24:38 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/20 11:05:32 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtins/builtins.h"

void	env(t_prog *term, t_cmd *cmd, char **envp)
// Executes the 'env' builtin command
{
	int	i;

	i = 0;
	if (cmd->argc > 1)
	{
		ft_dprintf(2, "env: \'%s\': No such file or directory\n", cmd->argv[1]);
		term->status = 127 << 8;
		free_split(&envp);
		return ;
	}
	while (envp[i] != NULL)
		ft_putendl_fd(envp[i++], cmd->fd_out);
	free_split(&envp);
	term->status = 0;
}

int	validate_export(char *arg, char **equals, int *plus)
// Validates syntax for an 'export' command
{
	*equals = ft_strchr(arg, '=');
	if (!ft_isalpha(*arg) && *arg != '_')
		return (0);
	while (*arg != 0 && *arg != '=' && *arg != '+')
	{
		if (!valid_var_chr(*arg))
			return (0);
		arg++;
	}
	if (*arg == '+' && *(arg + 1) != '=')
		return (0);
	if (*equals != NULL)
	{
		**equals = 0;
		(*equals)++;
		if (*arg == '+')
		{
			*arg = 0;
			*plus = 1;
		}
	}
	return (1);
}

void	print_export(t_prog *term, t_cmd *cmd)
{
	t_list	*current;
	t_env	*env;

	current = term->env_list;
	while (current != NULL)
	{
		env = (t_env *)current->content;
		ft_dprintf(cmd->fd_out, "declare -x %s=\"%s\"\n", env->name, env->var);
		current = current->next;
	}
}

void	export_env(t_prog *term, t_cmd *cmd, t_list *pipeline)
// Executes the 'export' builtin command
{
	int		i;

	if (cmd->argc < 2)
		print_export(term, cmd);
	else
	{
		if (ft_lstsize(pipeline) > 1)
			return ;
		i = 0;
		while (cmd->argv[++i] != NULL)
			envp_to_lst(term, cmd->argv[i], 0);
	}
}

void	unset_env(t_prog *term, t_cmd *cmd)
// Executes the 'unset' builtin command
{
	t_list	*env_node;
	t_env	*env;
	int		i;

	if (cmd->argc < 2)
		return ;
	i = 1;
	while (cmd->argv[i] != NULL)
	{
		env_node = getenv_node(term->env_list, cmd->argv[i++]);
		if (env_node != NULL)
		{
			env = (t_env *)env_node->content;
			free(env->var);
			env->var = NULL;
		}
	}
	term->status = 0;
}
