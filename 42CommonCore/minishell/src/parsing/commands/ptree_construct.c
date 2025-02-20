/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <fsmyth@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:57:14 by fsmyth            #+#    #+#             */
/*   Updated: 2025/02/14 18:58:06 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	push_ptree_stack(t_list	**stack, t_ptree *node)
{
	ft_lstadd_back(stack, ft_lstnew(node));
}

t_ptree	*pop_ptree_stack(t_list	**stack)
{
	t_list	*current;
	t_ptree	*out;

	current = *stack;
	if (current->next == NULL)
	{
		out = (t_ptree *)current->content;
		ft_lstclear(stack, NULL);
		return (out);
	}
	while (current->next->next != NULL)
		current = current->next;
	out = (t_ptree *)current->next->content;
	ft_lstdelone(current->next, NULL);
	current->next = NULL;
	return (out);
}

void	push_ptree_node(t_list **charstack, t_list **nodestack)
{
	t_ptree	*tree_node;

	tree_node = pop_ptree_stack(charstack);
	tree_node->right = pop_ptree_stack(nodestack);
	tree_node->left = pop_ptree_stack(nodestack);
	push_ptree_stack(nodestack, tree_node);
}

t_list	*construction_loop(t_list **charstack, t_list **nodestack,
							t_list *current)
{
	if (((t_ptree *)current->content)->op == OP_OPNPRN)
		push_ptree_stack(charstack, current->content);
	else if (((t_ptree *)current->content)->op == OP_NONE)
		push_ptree_stack(nodestack, current->content);
	else if (((t_ptree *)current->content)->op == OP_AND
		|| ((t_ptree *)current->content)->op == OP_OR)
	{
		while (*charstack != NULL && ((t_ptree *)
				ft_lstlast(*charstack)->content)->op != OP_OPNPRN)
			push_ptree_node(charstack, nodestack);
		push_ptree_stack(charstack, current->content);
	}
	else if (((t_ptree *)current->content)->op == OP_CLSPRN)
	{
		free_ptree_node(current->content, NULL);
		while (*charstack != NULL && ((t_ptree *)
				ft_lstlast(*charstack)->content)->op != OP_OPNPRN)
			push_ptree_node(charstack, nodestack);
		free_ptree_node(pop_ptree_stack(charstack), NULL);
	}
	return (current->next);
}

t_ptree	*construct_parse_tree(t_list **ptree_list)
{
	t_list	*current;
	t_list	*charstack;
	t_list	*nodestack;
	t_ptree	*tree_node;

	current = *ptree_list;
	charstack = NULL;
	nodestack = NULL;
	while (current != NULL)
		current = construction_loop(&charstack, &nodestack, current);
	while (charstack != NULL)
		push_ptree_node(&charstack, &nodestack);
	tree_node = (t_ptree *)(ft_lstlast(nodestack)->content);
	ft_lstclear(ptree_list, NULL);
	ft_lstclear(&nodestack, NULL);
	return (tree_node);
}
