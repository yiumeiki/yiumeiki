/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:00:13 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/20 11:05:21 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"
# include "../parsing/parsing.h"

void	echo(t_prog *term, t_cmd *cmd);
void	cd(t_prog *term, t_cmd *cmd, t_list *pipeline);
void	pwd(t_prog *term, t_cmd *cmd);
void	env(t_prog *term, t_cmd *cmd, char **envp);
void	export_env(t_prog *term, t_cmd *cmd, t_list *pipeline);
void	unset_env(t_prog *term, t_cmd *cmd);
void	exit_shell(t_prog *term, t_cmd *cmd);

#endif // BUILTINS_H
