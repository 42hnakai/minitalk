/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:56:59 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/01 21:27:07 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t bit = 0;

void signal_handler(int signum, siginfo_t *pid, void *context)
{
	static int count;
	static int pid2;
	char c;

	printf("%d", pid2);
	if (pid2 == 0)
		pid2 = pid->si_pid;
	bit = bit << 1;
	(void)context;
	if (signum == SIGUSR1)
	{
		bit |= 1;
		c = 0xff & bit;
		count++;
		if (count == 8)
		{
			write(STDOUT_FILENO, &c, 1);
			count = 0;
		}
		if (kill(pid2, SIGUSR1) == -1)
			printf("kill error!\n");
	}
	else if (signum == SIGUSR2)
	{
		c = 0xff & bit;
		count++;
		if (count == 8)
		{
			write(STDOUT_FILENO, &c, 1);
			count = 0;
		}
		if (kill(pid2, SIGUSR2) == -1)
			printf("kill error!\n");
	}
}

int main(void)
{
	pid_t my_pid;
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	my_pid = getpid();
	printf("%d\n", my_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
