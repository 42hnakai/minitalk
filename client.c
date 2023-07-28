/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:43:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/07/28 17:30:09 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(const pid_t pid, char c)
{
	int i;
	i = 7;
	while (i >= 0)
	{
		if (c && (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		sleep(200);
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
	split_into_chars(pid, argv[2]);
}