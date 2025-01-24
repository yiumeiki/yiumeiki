/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:46 by myiu              #+#    #+#             */
/*   Updated: 2024/10/10 15:50:48 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
To check if the philosopher has died
if yes, it updates their state, prints a death message
and cleans up resources before exiting
*/
int	check_dead(t_philo *philo)
{
	long	time;

	time = ft_time();
	if (time - philo->last_meal > philo->data->time_to_die)
	{
		philo->state = 1;
		time = time - philo->start_eat;
		sem_wait(philo->data->write);
		printf("%ld ms %d is died\n", time, philo->id);
		free_all(philo->data);
		exit(1);
	}
	return (0);
}

/*
Lock the fork
if only one philo, die and free the fork
else check if they die and lock the other fork
*/
int	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_status("%ld ms %d has taken a fork\n", philo);
	if (philo->data->size == 1)
	{
		ft_usleep(philo->data->time_to_die + 1, philo);
		sem_post(philo->data->forks);
		return (0);
	}
	else
	{
		if (check_dead(philo))
			return (0);
		sem_wait(philo->data->forks);
		print_status("%ld ms %d has taken a fork\n", philo);
	}
	return (1);
}

/*
Checks for an exceptional case for the last philosopher
if take_fork success, do eating action
after eating,free forks and check death
*/
void	eat(t_philo *philo)
{
	if (philo->data->exception && philo->id == philo->data->size
		&& philo->data->size != 1)
		ft_usleep(philo->data->time_to_die + 1, philo);
	if (take_forks(philo))
	{
		philo->nb_eat++;
		print_status("%ld ms %d is eating\n", philo);
		ft_usleep(philo->data->time_to_eat, philo);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		if (check_dead(philo))
			return ;
		philo->last_meal = ft_time();
		if (philo->nb_eat == philo->data->must_eat)
			exit(2);
	}
}

/*
Do sleeping and thinking action
*/
void	sleep_and_think(t_philo *philo)
{
	int	time;

	print_status("%ld ms %d is sleeping\n", philo);
	ft_usleep(philo->data->time_to_sleep, philo);
	if (check_dead(philo))
		return ;
	print_status("%ld ms %d is thinking\n", philo);
	if (philo->data->time_to_eat > philo->data->time_to_sleep)
	{
		time = philo->data->time_to_eat - philo->data->time_to_sleep - 1;
		ft_usleep(time, philo);
	}
}

/*
main loop of philos' action
step by step, check death(state flag) and then action
*/
void	action(t_philo	*philo)
{
	philo->last_meal = philo->start_eat;
	if (philo->id > (philo->data->size / 2) + 1)
		usleep(20000);
	while (!philo->state)
	{
		if (!philo->state)
			eat(philo);
		if (!philo->state)
			sleep_and_think(philo);
		if (!philo->state)
			usleep(100);
	}
}
