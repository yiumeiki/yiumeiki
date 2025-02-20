/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:57:45 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:51:23 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include <stdlib.h>

int	valid_var_chr(char c)
// Checks if a char is valid to be used in an environment variable name
{
	if (ft_isalnum(c))
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

void	expand_exit_status(char **line, char *varp, t_prog *term)
{
	char	*status;
	char	*expanded;

	status = ft_itoa(WEXITSTATUS(term->status));
	*varp = 0;
	varp++;
	expanded = ft_strdup(*line);
	expanded = ft_extend_line(expanded, status);
	expanded = ft_extend_line(expanded, varp);
	free(status);
	free(*line);
	*line = expanded;
}

void	apply_var_expansion(char **expanded, t_prog *term, char *varp, int i)
{
	char	*env_name;
	char	*env_var;

	env_name = ft_strndup(varp, i);
	env_var = getenv_list(term->env_list, env_name);
	if (env_var != NULL)
		*expanded = ft_extend_line(*expanded, env_var);
	*expanded = ft_extend_line(*expanded, &varp[i]);
	free(env_name);
}

int	expand_var_inplace(char **line, char *varp, t_prog *term, int quoting)
// Expands the environment variable at *varp in place.
// Returns 1 if variable name is valid so expansion is attempted.
// Returns 0 if no expansion attempted, leaving the '$' in place
{
	char	*expanded;
	int		i;

	*varp = 0;
	varp++;
	if (*varp == '?')
	{
		expand_exit_status(line, varp, term);
		return (1);
	}
	expanded = ft_strdup(*line);
	i = 0;
	while (valid_var_chr(varp[i]))
		i++;
	if (i == 0)
	{
		if (*varp != '\'' && *varp != '\"')
			return (free(expanded), 0);
		if (quoting == Q_DOUBLE && *varp == '\"')
			return (free(expanded), 0);
	}
	apply_var_expansion(&expanded, term, varp, i);
	free(*line);
	*line = expanded;
	return (1);
}

void	apply_quoting_expand(char *token, int *quoting, int i);

void	expand_token_var(char **token, t_prog *term)
// Expands all environment variables in a token not blocked by quoting
{
	char	*varp;
	int		i;
	int		quoting;

	i = 0;
	quoting = 0;
	while ((*token)[i])
	{
		if ((*token)[i] == '$' && quoting != Q_SINGLE)
		{
			varp = &(*token)[i];
			if (!expand_var_inplace(token, varp, term, quoting))
				*varp = '$';
			else
				continue ;
		}
		if ((*token)[i] == 0)
			break ;
		apply_quoting_expand(*token, &quoting, i);
		i++;
	}
}
