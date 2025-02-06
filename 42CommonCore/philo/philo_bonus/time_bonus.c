/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:36:42 by myiu              #+#    #+#             */
/*   Updated: 2025/02/06 13:30:21 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
returns the current time in milliseconds
*/
long	ft_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (time);
}

/*
Sleeps for a specified duration
crrected to shorter sleep intervals
*/
void	correct_usleep(long ms, long start)
{
	start = start + ms;
	if (ms > 10)
		usleep ((ms - 10) * 1000);
	while (1)
	{
		if (start < ft_time())
			return ;
		usleep(50);
	}
}

/*
Check if the philo's last meal time > the sleep duration
ensure the philo can die during sleep by checking their state
*/
void	ft_usleep(int time_ms, t_philo *philo)
{
	long	life_time;
	long	real_time;

	life_time = philo->last_meal + philo->data->time_to_die;
	real_time = ft_time();
	if (real_time + time_ms > life_time)
	{
		life_time = life_time - real_time;
		correct_usleep(life_time, real_time);
		if (philo->state == 1)
			return ;
		life_time = ft_time() - philo->start_eat;
		sem_wait(philo->data->write);
		printf("%ld %d is died\n", life_time, philo->id);
		free_all(philo->data);
		exit(1);
	}
	correct_usleep(time_ms, real_time);
}

/*
free all
*/
void	free_all(t_data	*data)
{
	if (data->forks)
		sem_close(data->forks);
	if (data->pid_all)
		free(data->philo);
	if (data->philo)
		free(data->pid_all);
}
