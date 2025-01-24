/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:58:34 by myiu              #+#    #+#             */
/*   Updated: 2024/07/14 19:04:26 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int	has_duplicates(int arr[4][4], int row_seen[4][4], int col_seen[4][4])
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = arr[i][j];
			if (row_seen[i][num - 1] || col_seen[j][num - 1])
			{
				print_error();
				return (1);
			}
			row_seen[i][num - 1] = 1;
			col_seen[j][num - 1] = 1;
			j++;
		}
		i++;
	}
	return (0);
}

void	just_for_norm(int row_seen[4][4], int col_seen[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row_seen[i][j] = 0;
			col_seen[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_criteria(int arr[4][4])
{
	char	ans;
	int		row_seen[4][4];
	int		col_seen[4][4];
	int		i;
	int		j;

	just_for_norm(row_seen, col_seen);
	if (has_duplicates(arr, row_seen, col_seen))
		return ;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ans = arr[i][j] + '0';
			write(1, &ans, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
