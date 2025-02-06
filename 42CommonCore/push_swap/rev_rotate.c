/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 17:42:57 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Shift down for stack(list)
*/
void	shift_down(t_stack **stack)
{
	t_stack	*last;
	t_stack	*new_last;
	t_stack	*curr;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	new_last = NULL;
	curr = *stack;
	while (curr->next != NULL)
	{
		new_last = curr;
		curr = curr->next;
	}
	new_last->next = NULL;
	ft_lstadd_front(stack, last);
}

/*
	operation: rra
*/
void	shift_down_a(t_stack **stack)
{
	shift_down(stack);
	ft_putstr_fd("rra\n", 1);
}

/*
	operation: rrb
*/
void	shift_down_b(t_stack **stack)
{
	shift_down(stack);
	ft_putstr_fd("rrb\n", 1);
}

/*
	operation: rrr
*/
void	shift_down_ab(t_stack **a, t_stack **b)
{
	shift_down(a);
	shift_down(b);
	ft_putstr_fd("rrr\n", 1);
}
