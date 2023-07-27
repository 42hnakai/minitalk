/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:56:59 by hnakai            #+#    #+#             */
/*   Updated: 2023/07/27 22:56:56 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signal_handler(int signum)
{
	static int	count;
	char		c;
	char		bit;
	c = 0xff;
	bit = '\0';
	bit = bit << 1;
	if(signum==SIGUSR1)
		bit |= 1;
	else if(signum==SIGUSR2)
		;
	c = c & bit;
	count++;
	if(count == 8)
	{
		write(1,&c,1);
		count = 0;
	}
}

int main( void)
{
	pid_t my_pid;
	my_pid = getpid();
	printf("%d",my_pid);
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
}
