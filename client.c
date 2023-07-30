/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:43:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/07/30 22:13:08 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int flag;

void signal_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		flag = 0;
	else
		flag = -1;
}

void send_signal(const pid_t pid, char c)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
		if (flag != 0)
			break;
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