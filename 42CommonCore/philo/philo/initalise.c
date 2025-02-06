/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:39:19 by myiu              #+#    #+#             */
/*   Updated: 2025/02/04 17:14:29 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Check if the philosopher died because of no eating
return 1 if died
*/
int	check_death(t_philo *ph, int i)
{
	int	died;

	pthread_mutex_lock(&ph->data->dead_mutex);
	if (i)
		ph->data->stop = i;
	died = ph->data->stop;
	pthread_mutex_unlock(&ph->data->dead_mutex);
	return (died);
}

/*
Checks if the philosopher died
if yes, wait a bit for other philosopers finishing actions
to join together and then destroy and free
*/
void	stop(t_ptr *p)
{
	int	i;

	i = -1;
	while (!check_death(p->ph, 0))
		ft_usleep(1);
	while (++i < p->data.philos)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->data.write_mutex);
	pthread_mutex_destroy(&p->data.dead_mutex);
	pthread_mutex_destroy(&p->data.time_eat_mutex);
	i = -1;
	while (++i < p->data.philos)
		pthread_mutex_destroy(&p->ph[i].left_fork);
	if (p->data.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->data.meals);
	free(p->ph);
}

/*
Print error message
*/
int	ft_exit(char *str)
{
	printf("Error : ");
	printf("%s", str);
	printf("./philo [Philos] [Die] [Eat] [Sleep]\n");
	return (0);
}

/*
for norminette;)
*/
void	init_mutex(t_ptr *p)
{
	pthread_mutex_init(&p->data.write_mutex, NULL);
	pthread_mutex_init(&p->data.dead_mutex, NULL);
	pthread_mutex_init(&p->data.time_eat_mutex, NULL);
	pthread_mutex_init(&p->data.finish_mutex, NULL);
}

/*
each philo get their own id, timestamp
right fork pointing to the next left fork
last philo pointing to first(circle table)
*/
int	initialize(t_ptr *p)
{
	int	i;

	i = 0;
	p->data.start_t = actual_time();
	p->data.stop = 0;
	p->data.number_philos_ate = 0;
	init_mutex(p);
	while (i < p->data.philos)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->data.start_t;
		p->ph[i].nb_philo_ate = 0;
		p->ph[i].finish = 0;
		p->ph[i].right_fork = NULL;
		pthread_mutex_init(&p->ph[i].left_fork, NULL);
		set_forks(p, i);
		i++;
	}
	return (1);
}
