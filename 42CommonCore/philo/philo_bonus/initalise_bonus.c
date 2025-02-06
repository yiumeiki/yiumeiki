/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalise_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:37:05 by myiu              #+#    #+#             */
/*   Updated: 2025/02/06 13:42:30 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
Initializes the struct t_data
*/
void	philo_data(t_data *data)
{
	int	i;

	if (data->error)
		return ;
	i = 0;
	data->philo->id = i + 1;
	data->philo->state = 0;
	data->philo->nb_eat = 0;
	data->philo->last_meal = 0;
	data->philo->start_eat = 0;
	data->philo->data = data;
	data->exception = 0;
	if (data->size % 2 && data->time_to_eat * 3 > data->time_to_die)
		data->exception = 1;
}

/*
malloc philo and pid
*/
void	allocate_all(t_data *data)
{
	pid_t	*tmp;
	t_philo	*philos;

	tmp = malloc(sizeof(pid_t) * (data->size));
	if (!tmp)
	{
		data->error--;
		return ;
	}
	philos = malloc(sizeof(t_philo));
	if (!philos)
	{
		free(tmp);
		data->error--;
		return ;
	}
	data->pid_all = tmp;
	data->philo = philos;
}

/*
for fork and write semaphores
unlinks any existing semaphores, creates new ones
checks for errors during semaphore initialization
*/
void	initalise_fork_write(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("write");
	data->forks = sem_open("forks", O_RDONLY | O_CREAT, 0664, data->size);
	if (data->forks == SEM_FAILED)
	{
		data->error--;
		printf("Error: opening semaphore\n");
		return ;
	}
	data->write = sem_open("write", O_RDONLY | O_CREAT, 0664, 1);
	if (data->write == SEM_FAILED)
	{
		data->error--;
		printf("Error: opening semaphore\n");
		return ;
	}
}

/*
Initializes the main data structure from user input
*/
void	initalise(char **av, t_data *data, int ac)
{
	data->error = 0;
	data->nb_full = 0;
	data->dead = 0;
	data->size = ft_atoi(av[1], data);
	data->time_to_die = ft_atoi(av[2], data);
	data->time_to_eat = ft_atoi(av[3], data);
	data->time_to_sleep = ft_atoi(av[4], data);
	data->must_eat = 2147483647;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5], data);
	data->start_time = 0;
	if (data->error || !data->size || !data->time_to_die)
	{
		data->error--;
		printf("Error: invalid input\n");
		return ;
	}
	allocate_all(data);
	philo_data(data);
	if (data->error)
		printf("Error: Allocation fail\n");
	initalise_fork_write(data);
}
