/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:56:59 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/01 21:49:20 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signum, siginfo_t *pid, void *context)
{
	static int	count;
	static int 	bit;

	bit = bit << 1;
	(void)context;
	if (signum == SIGUSR1)
		bit |= 1;
	count++;
	if (count == 8)
	{
		write(STDOUT_FILENO, &bit, 1);
		count = 0;
		bit = 0;
		if(kill(pid->si_pid,SIGUSR1)!=0)
			write(1,"[ERROR!] missing kill\n",22);
	}
}

int main(void)
{
	pid_t				my_pid;
	struct sigaction	sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	my_pid = getpid();
	printf("%d\n",my_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
