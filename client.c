/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:43:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/07/27 22:59:15 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_atoi.c"

void send_signal(const pid_t pid, char c)
{
	int i;
	i = 7;
	while(i >= 0)
	{
		if(c >> i)
			kill(pid,SIGUSR1);
		kill(pid,SIGUSR2);
		i++;
	}
}

void split_into_chars(const pid_t pid, char *str){
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		send_signal(pid,str[i]);
		i++;
	}
}

int main(int argc ,char **argv)
{
	int	pid;

	if(argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	split_into_chars(pid,argv[2]);
}