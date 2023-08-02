/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:04:35 by hnakai            #+#    #+#             */
/*   Updated: 2023/07/28 17:09:04 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
#define MINITALK_BONUS_H

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void		send_signal(const pid_t pid, char c);
void		split_into_chars(const pid_t pid, char *str);

#endif