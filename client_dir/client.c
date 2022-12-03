/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:45:41 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/03 20:10:34 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <stdlib.h>

void	send(int m, char *arg)
{
	static int	pid = 0;

	if (pid == 0)
		pid = ft_atoi(arg);
	kill(pid, m);
}

void	handler(int sig, siginfo_t *siginfo, void *p)
{
	siginfo = NULL;
	p = NULL;
	if (sig == SIGUSR1)
		send(30, NULL);
	if (sig == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("argument err");
		return (1);
	}
	send(31, argv[1]);
	send(30, NULL);
}
