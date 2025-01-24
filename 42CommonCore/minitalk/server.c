/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:52:38 by myiu              #+#    #+#             */
/*   Updated: 2025/01/15 17:10:35 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
	Builds a character from bits received via SIGUSR1 (1) and SIGUSR2 (0)
	When 8 bits are received, call function to write the character to stdout.
*/
void	handler(int sig)
{
	static int	bit;
	static char	c;

	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	else if (sig == SIGUSR2)
		c &= ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

/*
	Starts the server, displays its PID, and waits for signals from the client
	Using the basic signal function for handling
*/
int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server started\n", 15);
	write(1, "pid: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, ". \n", 3);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
