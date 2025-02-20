/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:36:43 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/03 20:27:30 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int	check_in_home(char *path, char *home)
// Checks if the path is within the HOME directory
{
	char	*terminated;
	size_t	size;

	if (home == NULL)
		return (0);
	size = ft_strlen(home) + 2;
	terminated = ft_calloc(size, 1);
	ft_strlcpy(terminated, home, size);
	if (ft_strncmp(path, terminated, size - 1) == 0)
		return (free(terminated), 1);
	ft_strlcat(terminated, "/", size);
	if (ft_strncmp(path, terminated, size - 1) == 0)
		return (free(terminated), 1);
	return (free(terminated), 0);
}

void	prompt_add_exit_status(char *prompt, int status, size_t prompt_size)
// Adds exit status of last command into the prompt.
{
	char	*status_str;

	status_str = ft_itoa(WEXITSTATUS(status));
	ft_strlcat(prompt, " \e[m\e[1;31m", prompt_size);
	ft_strlcat(prompt, status_str, prompt_size);
	ft_strlcat(prompt, "\e[m", prompt_size);
	free(status_str);
}

char	*get_prompt(t_prog *term, char *home)
// Constructs a string to be used as the prompt for readline()
{
	size_t	prompt_size;
	char	*path;

	free(term->prompt);
	prompt_size = ft_strlen(term->cwd) + 100;
	term->prompt = ft_calloc(prompt_size, 1);
	ft_strlcat(term->prompt, "\e[36m", prompt_size);
	ft_strlcat(term->prompt, getenv_list(term->env_list, "USER"), prompt_size);
	ft_strlcat(term->prompt, "\e[35m@minishell\e[m:\e[1;34m ", prompt_size);
	if (check_in_home(term->cwd, home))
	{
		ft_strlcat(term->prompt, "~", prompt_size);
		path = ft_substr(term->cwd, ft_strlen(home), PATH_MAX);
		ft_strlcat(term->prompt, path, prompt_size);
		free(path);
	}
	else
		ft_strlcat(term->prompt, term->cwd, prompt_size);
	if (term->status > 0)
		prompt_add_exit_status(term->prompt, term->status, prompt_size);
	ft_strlcat(term->prompt, "\e[1;32m > \e[m", prompt_size);
	return (term->prompt);
}
