/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:36:21 by myiu              #+#    #+#             */
/*   Updated: 2024/10/08 11:36:23 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
function atoi
and check input error(by "error" flag)
*/
int	ft_atoi(char	*str, t_data *data)
{
	int				neg;
	unsigned long	res;

	neg = 1;
	res = 0;
	while (*str && *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= 2147483648)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str != 0 || neg < 0 || (res > 2147483647 && neg > 0))
		data->error--;
	return ((int)res * neg);
}

/*
check if philo's state,0 = alive, 1 = die
if alive, print action using variables
lock and free semaphore
*/
void	print_status(char *str, t_philo *philo)
{
	long	time;

	sem_wait(philo->data->write);
	time = ft_time() - philo->start_eat;
	if (!philo->state)
		printf(str, time, philo->id);
	sem_post(philo->data->write);
}
