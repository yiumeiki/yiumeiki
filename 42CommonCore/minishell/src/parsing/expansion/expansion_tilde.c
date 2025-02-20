/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:37:01 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/18 16:04:31 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	expand_tilde_inplace(char **line, t_prog *term)
{
	char	*expanded;
	char	*tildep;
	char	*home;

	expanded = NULL;
	tildep = *line + 1;
	home = getenv_list(term->env_list, "HOME");
	if (home != NULL)
		expanded = ft_extend_line(expanded, home);
	else
		expanded = ft_extend_line(expanded, "~");
	expanded = ft_extend_line(expanded, tildep);
	free(*line);
	*line = expanded;
}

void	expand_token_tilde(char **token, t_prog *term)
{
	if (ft_strncmp(*token, "~", 2) == 0 || ft_strncmp(*token, "~/", 2) == 0)
		expand_tilde_inplace(token, term);
}
