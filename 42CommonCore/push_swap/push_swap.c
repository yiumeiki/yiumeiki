/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:04:47 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Find "target" value for each element in stack b
	This target value is used later to decide how to move elements 
	from stack b to stack a efficiently
*/
static void	find_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min_a;
	int		max_a;

	tmp_b = *b;
	min_a = min_value(a);
	max_a = max_value(a);
	while (tmp_b)
	{
		tmp_a = *a;
		tmp_b->target = max_a;
		while (tmp_a)
		{
			if (tmp_b->number > max_a)
				tmp_b->target = min_a;
			else if (tmp_a->number > tmp_b->number
				&& tmp_b->target >= tmp_a->number)
				tmp_b->target = tmp_a->number;
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

/*
	Sort larger stacks using a combination of push and shift operations.
	First, it pushes two elements stack b 
	Then a loop where it pushes elements to b if they are smaller than median.
	If an element in a is greater than the median, it is shifted up in a.
	Once the size of stack a == 3, it sorts the remaining using sort_three.
	After that, it repeatedly processes stack b
*/
static void	sort_big(t_stack **a, t_stack **b, int size, int median)
{
	push_b(a, b);
	push_b(a, b);
	while (size > 3)
	{
		if ((*a)->end_posit > median && size > median)
			shift_up_a(a);
		else
		{
			push_b(a, b);
			size--;
		}
		current_position(a);
		current_position(b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		current_position(a);
		current_position(b);
		find_target(a, b);
		get_cost(a, b);
		put_up_node(a, b);
		push_a(a, b);
	}
	sort_a(a);
}

/*
	Set and check agrv, set stack a
	check if is sorted : free ! call function based of size
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**params;
	int		size;

	params = set_input(av + 1);
	if (!params)
		return (0);
	check_args(params);
	stack_b = NULL;
	stack_a = set_stack(params, ac);
	if (!stack_a)
		return (0);
	size = ft_lstsize(stack_a);
	if (is_sort(&stack_a))
		free_stack(&stack_a, params, 1);
	if (size == 2)
		swap_a(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else
		sort_big(&stack_a, &stack_b, size - 2, size / 2);
	free_stack(&stack_a, params, 1);
	return (0);
}
