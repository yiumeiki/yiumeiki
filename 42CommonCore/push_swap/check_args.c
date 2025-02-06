/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:35:28 by myiu              #+#    #+#             */
/*   Updated: 2025/02/02 18:45:31 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	check if argv is number(can be both positive and negative)
	else: call handle_error
*/
static void	check_args_num(char **params)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	j = 0;
	i = 0;
	while (params[++k])
	{
		if (params[i][j] == '-' || params[i][j] == '+')
			j++;
		if (!params[i][j])
			handle_error(params);
		while (params[i][j] >= '0' && params[i][j] <= '9')
			j++;
		if (j != (int)ft_strlen(params[k]))
			handle_error(params);
		j = 0;
		i++;
	}
}

/*
	calculate the length of input
*/
static int	len_int(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

/*
	check if the int is vaild( <= int max and >= min)
*/
static void	check_args_size(char **params)
{
	int		i;
	int		nb;
	int		len;

	i = -1;
	while (params[++i])
	{
		nb = ft_atoi(params[i]);
		len = len_int(nb);
		if (params[i][0] == '+')
			len++;
		if (len != (int)ft_strlen(params[i]))
			handle_error(params);
	}
}

/*
	check if any repeat numbers in argv
*/
static void	check_double(char **params)
{
	int		i;
	int		j;

	i = -1;
	while (params[++i])
	{
		j = i;
		while (params[++j])
		{
			if (ft_atoi(params[i]) == ft_atoi(params[j]))
				handle_error(params);
		}
	}
}

/*
	entrance to call other functions
*/
void	check_args(char **params)
{
	check_args_num(params);
	check_args_size(params);
	check_double(params);
}
