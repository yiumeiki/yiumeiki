/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 18:00:04 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap top two elements in a stack if it has
*/
void	swap_stack(t_stack **stack)
{
	t_stack	*ptr_up;
	t_stack	*ptr_down;

	if (ft_lstsize(*stack) < 2)
		return ;
	ptr_up = *stack;
	ptr_down = (*stack)->next;
	ptr_up->next = (*stack)->next->next;
	ptr_down->next = ptr_up;
	*stack = ptr_down;
}

/*
	operation: sa
*/
void	swap_a(t_stack **a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

/*
	operation: sb
*/
void	swap_b(t_stack **b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}

/*
	operation: ss
*/
void	swap_s(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr_fd("ss\n", 1);
}
