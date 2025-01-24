/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:37:34 by myiu              #+#    #+#             */
/*   Updated: 2024/09/30 09:37:36 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

// structures
typedef struct s_data
{
	int						philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						stop;
	int						meals;
	int						number_philos_ate;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead_mutex;
	pthread_mutex_t			time_eat_mutex;
	pthread_mutex_t			finish_mutex;
}	t_data;

typedef struct s_philo
{
	int						id;
	int						finish;
	long int				ms_eat;
	unsigned int			nb_philo_ate;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_data					*data;
}	t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_data					data;
}	t_ptr;

//philo.c
int		main(int argc, char **argv);
int		args(int argc, char **argv, t_ptr *p);
void	print_status(char *str, t_philo *ph);
void	sleep_and_think(t_philo *ph);
void	action(t_philo *ph);

// initalise.c
void	init_mutex(t_ptr *p);
int		initialize(t_ptr *p);
void	stop(t_ptr *p);
int		check_death(t_philo *ph, int i);
int		ft_exit(char *str);

// threads.c
void	*is_dead(void	*data);
void	*thread(void *data);
int		threading(t_ptr *p);
void	ft_usleep(long int time_in_ms);
long	int	actual_time(void);

//helper.c
int		ft_atoi(const char *str);
int		is_number(char **argv, int i, int j);
void	*only_one(t_philo *ph);
void	odd_philo(t_philo *ph);
void	set_forks(t_ptr *p, int i);

#endif
