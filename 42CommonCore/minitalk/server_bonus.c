/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:27:02 by myiu              #+#    #+#             */
/*   Updated: 2025/01/15 17:10:04 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
	@sig: Signal identifier (SIGUSR1 or SIGUSR2).
	@info: Signal information structure (contains sender's PID).

	Builds a character from bits received via SIGUSR1 (1) and SIGUSR2 (0)
	When 8 bits are received, writes the characterto stdout 
	Sends a confirmation signal (SIGUSR1) to the client 
	if the null character is received
*/
void	handler(int sig, siginfo_t *info, void *ptr)
{
	static int	bit;
	static char	c;

	(void)ptr;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		if (!c)
		{
			usleep(300);
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
}

/*
	Starting the server, displays its PID, and waits for signals from the client
	Using sigaction to handle signals with extended information
*/
int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "Server started\n", 15);
	write(1, "pid: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, ". \n", 3);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
