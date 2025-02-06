/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:07:53 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	cost is the number of operations required from b to a
	4 cases:
	-Both positions are in the bottom half of their respective stacks
	-target is in the bottom half of a, but the node is in the top half of b
	-node is in the bottom half of b, but the target is in the top half of a
	-Both positions are in the top half of their respective stacks
*/
static void	calculate_cost(t_stack **a, t_stack *node, int size_a, int size_b)
{
	int	pos_a;
	int	pos_b;

	pos_a = target_pos(a, node->target);
	pos_b = node->cur_posit;
	if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		if ((size_a - pos_a) > (size_b - pos_b))
			node->count = (size_a - pos_a) + 1;
		else
			node->count = (size_b - pos_b) + 1;
	}
	else if (pos_a > size_a / 2 && pos_b <= size_b / 2)
		node->count = (size_a - pos_a) + pos_b + 1;
	else if (pos_a <= size_a / 2 && pos_b > size_b / 2)
		node->count = (size_b - pos_b) + pos_a + 1;
	else
	{
		if (pos_a > pos_b)
			node->count = pos_a;
		else
			node->count = pos_b;
	}
}

/*
	calling calculate_cost for each node in loop
*/
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (tmp)
	{
		calculate_cost(a, tmp, size_a, size_b);
		tmp = tmp->next;
	}
}
