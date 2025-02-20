/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:11:24 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 16:01:22 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input_line(t_prog *term, int hdoc)
{
	char	*line;
	char	*tmp;

	if (term->interactive)
	{
		if (hdoc)
			line = readline("> ");
		else
			line = readline(get_prompt(term,
						getenv_list(term->env_list, "HOME")));
	}
	else
	{
		tmp = get_next_line(fileno(stdin));
		if (tmp == NULL)
			return (tmp);
		line = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	return (line);
}

t_prog	*init_term(char **env)
// Initialises a t_prog structure
{
	t_prog			*prog;
	struct termios	term;

	prog = ft_calloc(1, sizeof(*prog));
	prog->status = 0;
	getcwd(prog->cwd, PATH_MAX);
	init_env_list(prog, env);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(fileno(stdin), TCSANOW, &term);
	if (isatty(fileno(stdin)))
		prog->interactive = 1;
	prog->line = get_input_line(prog, 0);
	return (prog);
}

t_prog	*start_program(int argc, char **argv, char *env[])
{
	t_prog	*term;

	(void)argc;
	(void)argv;
	setup_signals();
	term = init_term(env);
	return (term);
}
