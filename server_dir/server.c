/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:23:28 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/04 00:20:34 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <signal.h>

void	handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	pid = 0;
	static char	c = 0;
	static int	i = 0;

	ft_printf("here");
	if (pid == 0 || (siginfo->si_pid != 0 && siginfo->si_pid != pid))
		pid = siginfo->si_pid;
	p = NULL;
	if (sig == SIGUSR2)
		c += 0x80;
	c = c >> 1;
	i++;
	if (i >= 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(pid, SIGUSR2);
		i = 0;
	}
	kill(pid, SIGUSR1);
}

void	no(int sig, siginfo_t *siginfo, void *p)
{
	siginfo = NULL;
	p = NULL;
	ft_printf("fuck your %i", sig);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%i\n", getpid());
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
