/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:10:16 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:58:57 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_ptree	*ptree_new(t_list *pipeline, int op)
{
	t_ptree	*new;

	new = ft_calloc(1, sizeof(*new));
	new->pipeline = pipeline;
	new->op = op;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	free_ptree_node(t_ptree *ptree, void *null)
{
	(void)null;
	if (ptree->op == 0)
		free_pipeline(ptree->pipeline);
	ft_lstclear(&ptree->pids, free);
	free(ptree);
}

void	traverse_ptree(t_ptree *ptree, int order, void (*f)(t_ptree *, void *),
	void *data)
{
	if (ptree == NULL)
		return ;
	if (order == PRE_ORD)
		f(ptree, data);
	traverse_ptree(ptree->left, order, f, data);
	if (order == IN_ORD)
		f(ptree, data);
	traverse_ptree(ptree->right, order, f, data);
	if (order == PST_ORD)
		f(ptree, data);
}

void	print_ptree_node(t_ptree *ptree, void *null)
{
	(void)null;
	if (ptree->op > 0)
	{
		if (ptree->op == OP_AND)
			ft_printf("\e[1;32m&&\e[m ");
		else if (ptree->op == OP_OR)
			ft_printf("\e[1;31m||\e[m ");
		else if (ptree->op == OP_OPNPRN)
			ft_printf("\e[1;33m(e[m ");
		else if (ptree->op == OP_CLSPRN)
			ft_printf("\e[1;33m)e[m ");
	}
	else
		ft_printf("\e[1;34m%s\e[m ",
			(char *)((t_cmd *)ptree->pipeline->content)->tokens->content);
}

void	print_ptree_lst(t_list *ptree_list)
{
	t_list	*current;
	t_ptree	*node;

	current = ptree_list;
	while (current != NULL)
	{
		node = (t_ptree *)current->content;
		if (node->op == 0)
		{
			ft_printf("cmd: %s\n", (char *)
				((t_cmd *)node->pipeline->content)->tokens->content);
		}
		else
			ft_printf("op: %d\n", node->op);
		current = current->next;
	}
}
