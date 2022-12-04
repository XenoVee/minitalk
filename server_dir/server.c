/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:23:28 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/04 19:14:52 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <signal.h>

void	print_binary(char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 0x80) == 128)
			ft_printf("1");
		else
			ft_printf("0");
		c = c << 1;
		i++;
	}
	ft_printf("\n");
}

void	handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	pid = 0;
	static char	c = 0;
	static int	i = 0;

	if (pid == 0 || (siginfo->si_pid != 0 && siginfo->si_pid != pid))
		pid = siginfo->si_pid;
	p = NULL;
	if (sig == SIGUSR2)
		c |= 0x80 >> i;
	else
		c |= 0x0 >> i;
	i++;
	if (i >= 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(pid, SIGUSR2);
		c = 0;
		i = 0;
	}
	kill(pid, SIGUSR1);
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
