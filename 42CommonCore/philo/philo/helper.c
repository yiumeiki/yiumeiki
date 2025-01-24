/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:11:51 by myiu              #+#    #+#             */
/*   Updated: 2024/10/02 16:11:52 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Convert a string to an integer using ASCII
use ++i to prevent overflow
*/

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

/*
Check if the string is a number(valid input)
i = 0; j = 1(to skip the name)
*/

int	is_number(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	*only_one(t_philo *ph)
{
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
	ft_usleep(ph->data->time_to_die + 1);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("died\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
	pthread_mutex_unlock(&ph->left_fork);
	return (NULL);
}

void	odd_philo(t_philo *ph)
{
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("has taken a left fork\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
	if (!ph->right_fork)
	{
		ft_usleep(ph->data->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("has taken a right fork\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
}

void	set_forks(t_ptr *p, int i)
{
	if (p->data.philos == 1)
		p->ph[i].right_fork = &p->ph[i].left_fork;
	else
	{
		if (i == p->data.philos - 1)
			p->ph[i].right_fork = &p->ph[0].left_fork;
		else
			p->ph[i].right_fork = &p->ph[i + 1].left_fork;
	}
}
