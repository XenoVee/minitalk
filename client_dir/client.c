/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:45:41 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/04 19:29:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send(char *arg, char *pidstr)
{
	static int	pid = 0;
	static char	*binary = NULL;
	static int	i = 0;

	if (pid == 0)
		pid = ft_atoi(pidstr);
	if (binary == NULL)
		binary = arg;
	i++;
	if (binary[i - 1] == '1')
	{
		kill(pid, SIGUSR2);
	}
	if (binary[i - 1] == '0')
		kill(pid, SIGUSR1);
}

void	bitwise_conv(int i, int *j, char *str, char *ret)
{
	int	x;

	x = 0;
	while (x < 8)
	{
		if ((str[i] & 0x80) == 128)
			ret[*j + x] = '1';
		else
			ret[*j + x] = '0';
		str[i] = str[i] << 1;
		x++;
	}
	*j += x;
}

char	*binary_conv(char *str)
{
	char	*ret;
	int		i;
	int		j;

	ret = ft_calloc(sizeof(char), (ft_strlen(str) + 1) * 8);
	i = 0;
	j = 0;
	while (str[i])
	{
		bitwise_conv(i, &j, str, ret);
		i++;
	}
	bitwise_conv(i, &j, str, ret);
	ret[j] = '\0';
	return (ret);
}

void	handler(int sig, siginfo_t *siginfo, void *p)
{
	siginfo = NULL;
	p = NULL;
	if (sig == SIGUSR1)
		send(0, NULL);
	if (sig == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	char				*binary;

	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("Provide PiD and string");
		exit(1);
	}
	binary = binary_conv(argv[2]);
	send(binary, argv[1]);
	while (1)
	{
		pause();
	}
}
