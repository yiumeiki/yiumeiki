/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:36:03 by myiu              #+#    #+#             */
/*   Updated: 2024/10/08 11:36:06 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
Initializes the start time and forks processes for each philo
input the process ID to the t_data
*/
void	fork_process(t_data *data)
{
	int			i;
	pid_t		current_pid;
	t_philo		*philo;

	i = 0;
	philo = data->philo;
	data->start_time = ft_time();
	philo->start_eat = data->start_time;
	while (i < data->size)
	{
		philo->id = i + 1;
		current_pid = fork();
		if (!current_pid)
		{
			action(philo);
			break ;
		}
		else if (current_pid == -1)
			exit(-1);
		else
			data->pid_all[i] = current_pid;
		i++;
	}
}

/*
Waits for philosopher processes to exit
checks their exit status
*/
void	check_philos(t_data *data, int dead, char *str)
{
	int	i;
	int	check;

	(void)dead;
	while (data->nb_full < data->size)
	{
		waitpid(-1, &check, 0);
		if (WIFEXITED(check) && WEXITSTATUS(check) == 1)
		{
			data->dead++;
			break ;
		}
		else if (WIFEXITED(check) && WEXITSTATUS(check) == 2)
			data->nb_full++;
	}
	if (data->dead)
	{
		i = 0;
		while (i < data->size)
		{
			kill(data->pid_all[i], SIGKILL);
			i++;
		}
	}
	send_signal(data, str);
}

/*
print if all philosophers have eaten
*/
void	send_signal(t_data *data, char *str)
{
	if (data->nb_full == data->size && !data->dead)
		printf(str, data->must_eat);
}

/*
check input and call other functionssss
*/
int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		printf("Error: invalid input\n");
		return (0);
	}
	initalise(av, &data, ac);
	if (data.error)
		return (0);
	fork_process(&data);
	check_philos(&data, 0, "All philosophers ate %d meal(s)\n");
	usleep(10000);
	free_all(&data);
	if (data.write != SEM_FAILED)
		sem_post(data.write);
	sem_close(data.write);
	data.write = NULL;
	return (0);
}
