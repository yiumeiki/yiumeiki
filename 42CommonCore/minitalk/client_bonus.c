/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:26:48 by myiu              #+#    #+#             */
/*   Updated: 2025/01/15 17:08:06 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*	To see if server receive the signal or not*/
void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		write(1, "SERVER: signal received\n", 24);
	exit (1);
}

/*
	To send data bit by bit using signals
	by sending either SIGUSR1 (for 1) or SIGUSR2 (for 0)
	Pauses for a short time between signals to ensure the server processes them
*/
void	send_data(char c, int pid)
{
	int	index;
	int	flag;

	index = 7;
	flag = 0;
	(void)pid;
	while (index >= 0)
	{
		if ((c >> index) & 1)
			flag = kill(pid, SIGUSR1);
		else
			flag = kill(pid, SIGUSR2);
		index--;
		usleep(1000);
	}
	ft_error("", flag);
}

/*
	Sends a string message to the server identified by its PID
	check error and format: ./client_bonus <server_pid> <message>
*/
int	main(int ac, char **av)
{
	int	pid;
	int	index;

	index = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, ft_received);
		while (av[2][index])
			send_data(av[2][index++], pid);
		send_data('\0', pid);
		while (1)
			pause();
	}
	else
		write(1, "Error input\n", 12);
}
