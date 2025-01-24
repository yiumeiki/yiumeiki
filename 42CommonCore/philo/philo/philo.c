/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:38:01 by myiu              #+#    #+#             */
/*   Updated: 2024/09/30 09:38:02 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Print the current status of the philosopher.
The status includes (in this order):
[Time in ms since the start of an action]
[Philosopher's id]
[Current action (eating, sleeping, ...)]
*/

void	print_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = actual_time() - ph->data->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
	{
		printf("%ld ms ", time);
		printf("Philo %d %s", ph->id, str);
	}
}

/*
Philosopher sleeping and thinking action.
Lock->Sleep->Unlock->Lock->Think->Unlock.
*/

void	sleep_and_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
	ft_usleep(ph->data->time_to_sleep);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->data->write_mutex);
}

/*
Philosophers' eating action.
Take left fork->Take right fork->Eat->Release Forks->Sleep->Think
lock->print->unlock
*/

void	action(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_lock(ph->right_fork);
		pthread_mutex_lock(&ph->data->write_mutex);
		print_status("has taken a right fork\n", ph);
		pthread_mutex_unlock(&ph->data->write_mutex);
		pthread_mutex_lock(&ph->left_fork);
		pthread_mutex_lock(&ph->data->write_mutex);
		print_status("has taken a left fork\n", ph);
		pthread_mutex_unlock(&ph->data->write_mutex);
	}
	else
		odd_philo(ph);
	pthread_mutex_lock(&ph->data->write_mutex);
	print_status("is eating\n", ph);
	pthread_mutex_lock(&ph->data->time_eat_mutex);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->data->time_eat_mutex);
	pthread_mutex_unlock(&ph->data->write_mutex);
	ft_usleep(ph->data->time_to_eat);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(&ph->left_fork);
	sleep_and_think(ph);
}

/*
input data into the struct variables
*/
int	args(int argc, char **argv, t_ptr *ptr)
{
	if ((argc == 5 || argc == 6) && is_number(argv, 0, 1))
	{
		ptr->data.philos = ft_atoi(argv[1]);
		ptr->data.time_to_die = ft_atoi(argv[2]);
		ptr->data.time_to_eat = ft_atoi(argv[3]);
		ptr->data.time_to_sleep = ft_atoi(argv[4]);
		ptr->data.meals = -1;
		if (argc == 6)
			ptr->data.meals = ft_atoi(argv[5]);
		if (ptr->data.philos <= 0 || ptr->data.time_to_die <= 0
			|| ptr->data.time_to_eat <= 0 || ptr->data.time_to_sleep <= 0
			|| (argc == 6 && ptr->data.meals <= 0))
			return (0);
		return (1);
	}
	return (0);
}

/*
check input and print error
malloc and free
*/
int	main(int argc, char **argv)
{
	t_ptr		ptr;

	if (!(args(argc, argv, &ptr)))
		return (ft_exit("Invalid Arguments\n"));
	ptr.ph = malloc(sizeof(t_philo) * ptr.data.philos);
	if (!ptr.ph)
		return (ft_exit("Malloc returned NULL\n"));
	if (!initialize(&ptr) || !threading(&ptr))
	{
		free(ptr.ph);
		pthread_mutex_destroy(&ptr.data.write_mutex);
		pthread_mutex_destroy(&ptr.data.dead_mutex);
		pthread_mutex_destroy(&ptr.data.time_eat_mutex);
		return (0);
	}
	stop(&ptr);
	return (0);
}
