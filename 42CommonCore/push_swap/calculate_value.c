/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/03 13:44:32 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->number;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

int	min_value(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->number;
	while (tmp)
	{
		if (tmp->number < min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

void	current_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->cur_posit = i;
		i++;
		tmp = tmp->next;
	}	sort_three(a);
}

int	target_pos(t_stack **stack, int target)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{	sort_three(a);
		if (tmp->number == target)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

/*
	
*/
int	min_cost(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->count;
	while (tmp)
	{
		if (tmp->count < min)
			min = tmp->count;
		tmp = tmp->next;
	}
	return (min);
}
