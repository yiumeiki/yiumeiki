/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 17:55:20 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Called when both stacks need to move elements down
*/
static void	both_sup_med(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	position_a = target_pos(a, node->target);
	while (position_a < size_a && node->cur_posit < size_b)
	{
		shift_down_ab(a, b);
		position_a++;
		node->cur_posit++;
	}
	if (node->cur_posit == size_b)
	{
		while (position_a++ < size_a)
			shift_down_a(a);
	}
	else
	{
		while (node->cur_posit++ < size_b)
			shift_down_b(b);
	}
}

/*
	Called when both stacks need to move elements up
*/
static void	both_inf_med(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	position_b;

	position_a = target_pos(a, node->target);
	position_b = node->cur_posit;
	while (position_a != 0 && position_b != 0)
	{
		shift_up_ab(a, b);
		position_a--;
		position_b--;
	}
	if (position_b == 0)
	{
		while (position_a-- != 0)
			shift_up_a(a);
	}
	else
	{
		while (position_b-- != 0)
			shift_up_b(b);
	}
}

/*
	Called when the position in stack a is greater than half the size of a, 
	but the position in stack b is greater than the current size of b.
*/
static void	b_sup_med(t_stack **a, t_stack **b, t_stack *node, int size_b)
{
	int	position_a;
	int	position_b;

	position_a = target_pos(a, node->target);
	position_b = node->cur_posit;
	while (position_a != 0)
	{
		shift_up_a(a);
		position_a--;
	}
	while (position_b < size_b)
	{
		shift_down_b(b);
		position_b++;
	}
}

/*
	Called when the position in stack b is greater than zero (not at the top)
	and the position in stack a is not yet at its target.
*/
static void	b_inf_med(t_stack **a, t_stack **b, t_stack *node, int size_a)
{
	int	position_a;
	int	position_b;

	position_a = target_pos(a, node->target);
	position_b = node->cur_posit;
	while (position_b != 0)
	{
		shift_up_b(b);
		position_b--;
	}
	while (position_a < size_a)
	{
		shift_down_a(a);
		position_a++;
	}
}

/*
	Chooses which function to use for each node in b based on its position
	and the positions of the target elements in stack a.
	it checks if the cost is 1 or the minimum cost (min_cost)
	which is a more efficient way to move the node.
*/
void	put_up_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		position_a;
	int		size_a;
	int		size_b;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (tmp)
	{
		if (tmp->count == 1 || tmp->count == min_cost(b))
		{
			position_a = target_pos(a, tmp->target);
			if (position_a > size_a / 2 && tmp->cur_posit > size_b / 2)
				both_sup_med(a, b, tmp);
			else if (position_a <= size_a / 2 && tmp->cur_posit <= size_b / 2)
				both_inf_med(a, b, tmp);
			else if (position_a <= size_a && tmp->cur_posit > size_b / 2)
				b_sup_med(a, b, tmp, size_b);
			else
				b_inf_med(a, b, tmp, size_a);
			break ;
		}
		tmp = tmp->next;
	}
}
