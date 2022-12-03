/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:23:28 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/03 20:17:39 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <signal.h>

void	handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	pid = 0;

	if (pid == 0)
		pid = siginfo->si_pid;
	p = NULL;
	ft_printf("signal got: %i\n", sig);
	if (sig == SIGUSR1)
		kill(pid, SIGUSR1);
	if (sig == SIGUSR2)
		kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
