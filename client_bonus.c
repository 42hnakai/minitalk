/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:43:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/02 22:33:58 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "received signal!\n", 17);
}

void	send_signal(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
		{
			if (kill(pid, SIGUSR1) != 0)
				write(1,"[ERROR!] missing kill\n",22);
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				write(1,"[ERROR!] missing kill\n",22);
		}
		digit--;
		usleep(200);
	}
	usleep(100);
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
	if(pid < 100 || 99998 < pid)
		write(1,"[ERROR!] invalid pid\n",21);
	signal(SIGUSR1,signal_handler);
	split_into_chars(pid, argv[2]);
	return (0);
}
