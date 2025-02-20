/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:50:15 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:07:30 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/wait.h>

void	cleanup(t_prog *term)
// Cleans up the t_prog struct before exit
{
	ft_lstclear(&term->env_list, free_env);
	rl_clear_history();
	free(term->prompt);
	free(term);
}

int	main(int argc, char **argv, char *env[])
{
	t_prog	*term;
	t_ptree	*ptree;

	term = start_program(argc, argv, env);
	while (term->line != NULL)
	{
		if (*term->line == 0 || ft_strwhitespace(term->line))
		{
			free(term->line);
			term->line = get_input_line(term, 0);
			continue ;
		}
		ptree = parse_line(term->line, term);
		if (term->parse_status == 0)
			execute_ptree(ptree, term);
		traverse_ptree(ptree, PST_ORD, free_ptree_node, NULL);
		term->ptree = NULL;
		add_history(term->line);
		free(term->line);
		term->line = get_input_line(term, 0);
	}
	handle_eof(term);
}
