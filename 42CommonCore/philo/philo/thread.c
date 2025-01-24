/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:37:47 by myiu              #+#    #+#             */
/*   Updated: 2024/10/02 16:37:48 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Make the philosopher wait
by stopping for a little bit many times
so other philosophers can do other things at the same time
*/

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;
	long int	passed_time;

	passed_time = 0;
	start_time = actual_time();
	while (passed_time < time_in_ms)
	{
		passed_time = actual_time() - start_time;
		usleep(100);
	}
}

/*
Calculate the actual time in ms
using long int for calculatation of milliseconds/ seconds/ microseconds
*/

long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

/*
when a philosopher died, unlock timr_eat_mutex and finish_mutex
lock write_mutex and print and then unlock
*/

void	*is_dead(void	*data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->data->time_to_die);
	pthread_mutex_lock(&ph->data->time_eat_mutex);
	pthread_mutex_lock(&ph->data->finish_mutex);
	if (!check_death(ph, 0) && ((actual_time() - ph->ms_eat) \
		> (long)(ph->data->time_to_die)))
	{
		pthread_mutex_unlock(&ph->data->time_eat_mutex);
		pthread_mutex_unlock(&ph->data->finish_mutex);
		pthread_mutex_lock(&ph->data->write_mutex);
		print_status("died\n", ph);
		pthread_mutex_unlock(&ph->data->write_mutex);
		check_death(ph, 1);
	}
	else
	{
		pthread_mutex_unlock(&ph->data->time_eat_mutex);
		pthread_mutex_unlock(&ph->data->finish_mutex);
	}
	return (NULL);
}

/*
Make even philosophers start with a delay
Thread function that simulates the behavior of a philosopher.
It creates a new thread to check whether the philosopher has
died, and then performs the philosopher's actions.
Keeps track of how many times the philosopher has eaten.
*/

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	pthread_create(&ph->thread_death_id, NULL, is_dead, data);
	if (ph->data->philos == 1)
		only_one(ph);
	if (ph->id % 2 == 0)
		ft_usleep(ph->data->time_to_eat / 10);
	while (1)
	{
		if (check_death(ph, 0))
			break ;
		action(ph);
		if (ph->data->meals != -1 && (int)++ph->nb_philo_ate == ph->data->meals)
		{
			pthread_mutex_lock(&ph->data->finish_mutex);
			ph->finish = 1;
			ph->data->number_philos_ate++;
			if (ph->data->number_philos_ate == ph->data->philos)
				check_death(ph, 2);
			pthread_mutex_unlock(&ph->data->finish_mutex);
		}
	}
	pthread_join(ph->thread_death_id, NULL);
	return (NULL);
}

/*
Create a thread for each philosopher
*/

int	threading(t_ptr *p)
{
	int	i;

	i = 0;
	while (i < p->data.philos)
	{
		p->ph[i].data = &p->data;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]) != 0)
			return (ft_exit("Pthread did not return 0\n"));
		i++;
	}
	return (1);
}
