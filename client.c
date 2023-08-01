/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:43:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/01 21:53:10 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int flag = -1;

void signal_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		flag = 0;
	else
		flag = -1;
}

void send_signal(const pid_t pid, char c)
{
	int digit;

	digit = 7;
	while (digit >= 0)
	{
		flag = -1;
		if (c & (1 << digit))
		{
			if (kill(pid, SIGUSR1) != 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				exit(1);
		}
		digit--;
		usleep(100);
		while (flag == -1)
			pause();
	}
}

void split_into_chars(const pid_t pid, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		send_signal(pid, str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	split_into_chars(pid, argv[2]);
	return (0);
}