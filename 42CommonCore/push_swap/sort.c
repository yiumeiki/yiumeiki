/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:04:47 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	check if stack a is sorted
*/
int	is_sort(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	tmp = *a;
	count = 1;
	if (*a == NULL)
		return (0);
	if ((*a)->next)
	{
		while (tmp->next && tmp->next->number > tmp->number)
		{
			count++;
			tmp = tmp->next;
		}
	}
	if (count == ft_lstsize(*a))
		return (1);
	else
		return (0);
}

/*
	hardcore for sorting 3 elements
*/
void	sort_three(t_stack **a)
{
	t_stack	*tmp;

	if (is_sort(a))
		return ;
	tmp = *a;
	if (tmp->number == max_value(a))
	{
		shift_up_a(a);
		if (!is_sort(a))
			swap_a(a);
	}
	else if (tmp->next->number == max_value(a))
	{
		shift_down_a(a);
		if (!is_sort(a))
			swap_a(a);
	}
	else
		swap_a(a);
}

/*
	Move the smallest element to the top:
	check the position of the element, shift it to the top recursively
*/
void	sort_a(t_stack **a)
{
	t_stack	*tmp;
	int		size;
	int		min;

	tmp = *a;
	size = ft_lstsize(*a);
	min = min_value(a);
	current_position(a);
	while (tmp)
	{
		if (tmp->number == min)
		{
			while (tmp->cur_posit != 0)
			{
				if (tmp->cur_posit <= size / 2)
					shift_up_a(a);
				else
					shift_down_a(a);
				current_position(a);
			}
			break ;
		}
		tmp = tmp->next;
	}
}
