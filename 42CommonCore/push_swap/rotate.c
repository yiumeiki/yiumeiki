/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 17:43:38 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	shift up for stack(list)
*/
void	shift_up(t_stack **stack)
{
	t_stack	*ptr_up;

	if (ft_lstsize(*stack) < 2)
		return ;
	ptr_up = *stack;
	*stack = (*stack)->next;
	ptr_up->next = NULL;
	ft_lstadd_back(stack, ptr_up);
}

/*
	operation: ra
*/
void	shift_up_a(t_stack **a)
{
	shift_up(a);
	ft_putstr_fd("ra\n", 1);
}

/*
	operation: rb
*/
void	shift_up_b(t_stack **b)
{
	shift_up(b);
	ft_putstr_fd("rb\n", 1);
}

/*
	operation: rr
*/
void	shift_up_ab(t_stack **a, t_stack **b)
{
	shift_up(a);
	shift_up(b);
	ft_putstr_fd("rr\n", 1);
}
