/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:24:45 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:05:37 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parsing/parsing.h"

unsigned char	get_exit_code(char *arg, char **endptr)
{
	long	num;

	errno = 0;
	num = ft_strtol(arg, endptr, 10);
	if (*arg != 0 && **endptr == 0 && errno != ERANGE)
		return (num);
	else
	{
		ft_putstr_fd("\e[32mminishell: \e[35mexit:\e[m ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": numeric argument required", 2);
		return (2);
	}
}

void	exit_shell(t_prog *term, t_cmd *cmd)
{
	int		status;
	char	*endptr;

	status = term->status;
	if (cmd->argc != 1)
		status = get_exit_code(cmd->argv[1], &endptr) << 8;
	if (cmd->argc > 2 && *endptr == 0)
	{
		ft_putendl_fd("\e[32mminishell: \e[35mexit: \e[mtoo many arguments", 2);
		term->status = 1 << 8;
		return ;
	}
	traverse_ptree(term->ptree, PST_ORD, free_ptree_node, NULL);
	free(term->line);
	cleanup(term);
	exit(WEXITSTATUS(status));
}
