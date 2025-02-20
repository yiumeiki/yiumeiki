/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:07:01 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/19 18:07:35 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_syntax_err(t_list *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (token != NULL)
		ft_putstr_fd((char *)token->content, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putendl_fd("\'", 2);
}
