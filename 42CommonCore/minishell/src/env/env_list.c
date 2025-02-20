/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:45:55 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 16:00:46 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*getenv_node(t_list *env_list, char *name)
// Returns the env_list node matching with name matching 'name'
{
	t_list	*current;
	char	*env_name;

	current = env_list;
	while (current != NULL)
	{
		env_name = ((t_env *)current->content)->name;
		if (!ft_strncmp(env_name, name, ft_strlen(name) + 1))
			break ;
		current = current->next;
	}
	if (current == NULL)
		return (NULL);
	return (current);
}

char	*getenv_list(t_list *env_list, char *name)
// Returns the environment variable with name matching 'name'
{
	t_env	*env;
	t_list	*node;

	node = getenv_node(env_list, name);
	if (node == NULL)
		return (NULL);
	env = (t_env *)(node->content);
	if (env == NULL)
		return (NULL);
	return (env->var);
}

char	*get_shell(t_prog *term, char *name)
// Returns the path of the running minishell executable
{
	size_t	len;
	char	*shell;

	if (name[0] == '.' && name[1] == '/')
		name += 2;
	len = 2;
	len += ft_strlen(term->cwd);
	len += ft_strlen(name);
	shell = ft_calloc(len, 1);
	ft_strlcpy(shell, term->cwd, len);
	ft_strlcat(shell, "/", len);
	ft_strlcat(shell, name, len);
	return (shell);
}

void	env_list_add(t_list **env_list, char *name, char *var)
// Adds a new environment variable to the env_list, with
// name 'name' and variable 'var'.
{
	t_env	*env;

	env = ft_calloc(1, sizeof(*env));
	env->name = ft_strdup(name);
	if (var != NULL)
		env->var = ft_strdup(var);
	else
		env->var = NULL;
	ft_lstadd_back(env_list, ft_lstnew(env));
}

void	init_env_list(t_prog *term, char **env)
// Initialises the env_list with variables in the shell's enviromnent
{
	int		i;
	int		shlvl;
	char	*shlvl_str;

	i = 0;
	while (env[i] != NULL)
		envp_to_lst(term, env[i++], 1);
	shlvl = ft_atoi(getenv_list(term->env_list, "SHLVL")) + 1;
	shlvl_str = ft_itoa(shlvl);
	env_change_or_add(term, "SHLVL", shlvl_str, 0);
	free(shlvl_str);
}
