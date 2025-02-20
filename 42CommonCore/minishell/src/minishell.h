/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:39:32 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/20 11:07:37 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/wait.h>
# include <termios.h>
# include "structs.h"

//Main
void	cleanup(t_prog *term);
char	*get_prompt(t_prog *term, char *home);
char	*get_input_line(t_prog *term, int hdoc);
t_prog	*start_program(int argc, char **argv, char *env[]);

//Entries
t_list	*get_entries(t_prog *term);
void	print_entries(t_list *entries);

//Exec
int		count_args(char **args);
int		search_path(t_prog *term, char *cmd, char *cmd_path);
int		exec_cmd(t_prog *term, t_cmd *cmd, t_list *pipeline, t_list *cur_cmd);
void	execute_pipeline(t_ptree *treenode, t_prog *term);
void	execute_ptree(t_ptree *ptree, t_prog *term);
int		handle_builtins(t_prog *term, t_cmd *cmd, t_list *pipeline);
void	handle_child(t_cmd *cmd, t_prog *term,
			t_list *pipeline, char *cmd_path);

//Env
void	free_env(void *env);
t_list	*getenv_node(t_list *env_list, char *name);
char	*getenv_list(t_list *env_list, char *name);
void	init_env_list(t_prog *term, char **env);
void	env_list_add(t_list **lst, char *name, char *var);
char	*construct_envp_line(char *name, char *env);
char	**construct_envp(t_list *list);
void	envp_to_lst(t_prog *term, char *envp, int init);
void	env_change_or_add(t_prog *term, char *name, char *var, int plus);

//Signals
void	sig_handler(int sig);
void	hdoc_handler(int signum);
void	setup_signals(void);
void	handle_eof(t_prog *term);
void	reset_child_sig(void);
#endif
