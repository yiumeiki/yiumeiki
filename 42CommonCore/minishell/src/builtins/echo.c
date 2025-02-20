/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:58:13 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:06:51 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins/builtins.h"

void	handle_echo_opts(char **argv, int *i, int *nl)
{
	int	j;

	if (argv[*i] == NULL)
		return ;
	while (*argv[(*i)] == '-')
	{
		j = 1;
		while (argv[*i][j] == 'n')
			j++;
		if (argv[*i][j] != 0 || j == 1)
			break ;
		*nl = 0;
		(*i)++;
		if (argv[*i] == NULL)
			return ;
	}
}

void	echo(t_prog *term, t_cmd *cmd)
// Executes the 'echo' builtin command
{
	int		i;
	int		nl;
	int		first_arg;

	if (cmd->argc < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		nl = 1;
		handle_echo_opts(cmd->argv, &i, &nl);
		first_arg = i;
		while ((cmd->argv)[i] != NULL)
		{
			if (i != first_arg)
				write(cmd->fd_out, " ", 1);
			ft_putstr_fd((cmd->argv)[i++], cmd->fd_out);
		}
		if (nl == 1)
			write(cmd->fd_out, "\n", 1);
	}
	term->status = 0;
}
