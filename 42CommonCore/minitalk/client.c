/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:52:27 by myiu              #+#    #+#             */
/*   Updated: 2025/01/15 17:08:26 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
	To send data bit by bit using signals
	by sending either SIGUSR1 (for 1) or SIGUSR2 (for 0)
	Pauses for a short time between signals to ensure the server processes them
*/
void	send_data(char c, int pid)
{
	int	bit;
	int	flag;

	bit = 7;
	flag = 0;
	(void)pid;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			flag = kill(pid, SIGUSR1);
		else
			flag = kill(pid, SIGUSR2);
		bit--;
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
		while (av[2][index])
			send_data(av[2][index++], pid);
		send_data('\0', pid);
	}
	else
		write(1, "Error : Format ./client <server_pid> <message>\n", 48);
}
