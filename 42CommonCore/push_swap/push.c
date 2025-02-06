/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/01 19:53:22 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	operation: pb
*/
void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*a) < 1)
		return ;
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = NULL;
	ft_lstadd_front(b, ptr);
	ft_putstr_fd("pb\n", 1);
}

/*
	operation: pa
*/
void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*b) < 1)
		return ;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
	ft_putstr_fd("pa\n", 1);
}

/*
	below is for checker(bonus)
*/
void	silent_push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*a) < 1)
		return ;
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = NULL;
	ft_lstadd_front(b, ptr);
}

void	silent_push_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*b) < 1)
		return ;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
}
