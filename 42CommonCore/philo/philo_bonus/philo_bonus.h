/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:14:28 by myiu              #+#    #+#             */
/*   Updated: 2024/10/09 11:14:32 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				id;
	int				state;
	int				nb_eat;
	long			last_meal;
	long			start_eat;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				size;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				nb_full;
	int				dead;
	int				error;
	int				exception;
	long			start_time;
	pid_t			*pid_all;
	sem_t			*forks;
	sem_t			*write;
	t_philo			*philo;
}			t_data;

//philo_bonus.c
void		fork_process(t_data *data);
void		check_philos(t_data *data, int dead, char *str);
void		send_signal(t_data *data, char *str);
int			main(int ac, char **av);

// threads_bonus.c
long		ft_time(void);
void		correct_usleep(long ms, long start);
void		ft_usleep(int time_ms, t_philo *philo);
void		free_all(t_data	*data);

// initalise_bonus.c
void		initalise(char **av, t_data *data, int ac);
void		philo_data(t_data *data);
void		allocate_all(t_data *data);
void		initalise_fork_write(t_data *data);

// action_bonus.c
int			check_dead(t_philo *philo);
int			take_forks(t_philo *philo);
void		eat(t_philo *philo);
void		sleep_and_think(t_philo *philo);
void		action(t_philo	*philo);

//helper_bonus.c
int			ft_atoi(char	*str, t_data *data);
void		print_status(char *str, t_philo *philo);

#endif