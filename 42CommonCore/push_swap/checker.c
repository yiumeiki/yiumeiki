/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:09:17 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
	handling remain stack operations that involve both stacks at the same time
*/
static void	check_move2(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (!ft_strncmp(move, "rr\n", ft_strlen(move)))
	{
		shift_up(a);
		shift_up(b);
	}
	else if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
	{
		shift_down(a);
		shift_down(b);
	}
}

/*
	checks for multiple different operations based on the command provided.
*/
static void	check_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", ft_strlen(move)))
		swap_stack(a);
	else if (!ft_strncmp(move, "sb\n", ft_strlen(move)))
		swap_stack(b);
	else if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
		check_move2(a, b, move);
	else if (!ft_strncmp(move, "pa\n", ft_strlen(move)))
		silent_push_a(a, b);
	else if (!ft_strncmp(move, "pb\n", ft_strlen(move)))
		silent_push_b(a, b);
	else if (!ft_strncmp(move, "ra\n", ft_strlen(move)))
		shift_up(a);
	else if (!ft_strncmp(move, "rb\n", ft_strlen(move)))
		shift_up(b);
	else if (!ft_strncmp(move, "rr\n", ft_strlen(move)))
		check_move2(a, b, move);
	else if (!ft_strncmp(move, "rra\n", ft_strlen(move)))
		shift_down(a);
	else if (!ft_strncmp(move, "rrb\n", ft_strlen(move)))
		shift_down(b);
	else if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
		check_move2(a, b, move);
	else
		write(2, "Error\n", 6);
}

/*
	check if a is sorted and b is empty, then free both
*/
static void	check_stack(char **args, t_stack **a, t_stack **b)
{
	if (!is_sort(a) || ft_lstsize(*b))
		ft_putstr_fd("KO\n", 1);
	if (is_sort(a) && !ft_lstsize(*b))
		ft_putstr_fd("OK\n", 1);
	free_stack(a, 0, 0);
	free_stack(b, args, 1);
}

/*
	set input(av + 1 to skip the prog name)
	call other functions
	free at the end
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*move;
	char	**input;

	input = set_input(av + 1);
	if (!input)
		return (0);
	check_args(input);
	stack_b = NULL;
	stack_a = set_stack(input, ac);
	move = get_next_line(0);
	while (move)
	{
		check_move(&stack_a, &stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	if (move)
		free(move);
	check_stack(input, &stack_a, &stack_b);
	return (0);
}
