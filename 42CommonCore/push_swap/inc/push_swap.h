/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 19:04:47 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				number;
	int				end_posit;
	int				cur_posit;
	int				target;
	int				count;
	struct s_stack	*next;
}	t_stack;

//PARSING_ARGS.C
char	**set_input(char **av);

//CHECK_ARGS.C
void	check_args(char **params);

//LST_MANAGE.C
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);

//SET_STACK.C
t_stack	*set_stack(char **av, int ac);

//GET_VAL_MISC.C
int		max_value(t_stack **stack);
int		min_value(t_stack **stack);
void	current_position(t_stack **stack);
int		target_pos(t_stack **stack, int target);
int		min_cost(t_stack **stack);

//COST_ANALISYS.C
void	get_cost(t_stack **a, t_stack **b);

//PUT_UP_NODE.C
void	put_up_node(t_stack **a, t_stack **b);

//SORT.C
void	sort_three(t_stack **a);
void	sort_a(t_stack **a);
int		is_sort(t_stack **a);

//UTILS.C
void	free_stack(t_stack **stack, char **args, int quit);
void	handle_error(char	**tab);
void	free_args(char **tab);

/*
	below is the movement
*/

//PUSH.C
void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	silent_push_b(t_stack **a, t_stack **b);
void	silent_push_a(t_stack **a, t_stack **b);

//SWAP.C
void	swap_stack(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_s(t_stack **a, t_stack **b);

//ROTATE.C
void	shift_up(t_stack **stack);
void	shift_up_a(t_stack **a);
void	shift_up_b(t_stack **b);
void	shift_up_ab(t_stack **a, t_stack **b);

//REV_ROTATE.C
void	shift_down(t_stack **stack);
void	shift_down_a(t_stack **down);
void	shift_down_b(t_stack **down);
void	shift_down_ab(t_stack **a, t_stack **b);

#endif