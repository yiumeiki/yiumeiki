/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:43:31 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/07 17:34:34 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	validate_export(char *arg, char **equals, int *plus);

void	free_env(void *data)
// Frees a t_env struct
{
	t_env	*env;

	env = (t_env *)data;
	free(env->name);
	free(env->var);
	free(env);
}

char	*construct_envp_line(char *name, char *env)
// Constructs a line to be used in the **envp array
{
	size_t	len;
	char	*line;

	len = ft_strlen(name);
	len += ft_strlen(env);
	line = ft_calloc(len + 2, 1);
	ft_strlcpy(line, name, len + 2);
	ft_strlcat(line, "=", len + 2);
	ft_strlcat(line, env, len + 2);
	return (line);
}

void	env_change_or_add(t_prog *term, char *name, char *var, int plus)
{
	t_list	*existing;
	char	*tmp;

	existing = getenv_node(term->env_list, name);
	if (existing == NULL)
		env_list_add(&term->env_list, name, var);
	else
	{
		if (!plus)
		{
			free(((t_env *)existing->content)->var);
			((t_env *)existing->content)->var = ft_strdup(var);
		}
		else
		{
			tmp = ft_extend_line(((t_env *)existing->content)->var, var);
			ft_printf("tmp: %s\n", tmp);
			((t_env *)existing->content)->var = tmp;
		}
	}
}

void	envp_to_lst(t_prog *term, char *envp, int init)
{
	char	*equals;
	int		plus;

	plus = 0;
	if (!validate_export(envp, &equals, &plus))
	{
		if (!init)
		{
			term->status = 1 << 8;
			ft_dprintf(2, "minishell: export: `%s\'", envp);
			ft_dprintf(2, ": not a valid identifier\n", envp);
		}
		return ;
	}
	env_change_or_add(term, envp, equals, plus);
	term->status = 0;
}

char	**construct_envp(t_list *env_list)
// Constructs the **envp array to pe passed to execve() calls
{
	char	**envp;
	t_list	*current;
	t_env	*env;
	int		i;

	current = env_list;
	envp = ft_calloc(ft_lstsize(env_list) + 1, sizeof(char *));
	i = 0;
	while (current != NULL)
	{
		env = (t_env *)current->content;
		if (env->var != NULL)
			envp[i++] = construct_envp_line(env->name, env->var);
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}
