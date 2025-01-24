/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:33:44 by myiu              #+#    #+#             */
/*   Updated: 2024/07/25 17:43:00 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solutions(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	ft_check(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row
			|| board[i] + i == col + row)
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve(int *board, int row, int *total_solutions)
{
	int	col;

	if (row == 10)
	{
		ft_print_solutions(board);
		(*total_solutions)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (ft_check(board, row, col))
		{
			board[row] = col;
			ft_solve(board, row + 1, total_solutions);
			board[row] = -1;
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	total_solutions;

	i = 0;
	while (i < 10)
		board[i++] = -1;
	total_solutions = 0;
	ft_solve(board, 0, &total_solutions);
	return (total_solutions);
}
