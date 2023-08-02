/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:04:35 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/02 21:34:32 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
#define MINITALK_BONUS_H

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void		send_signal(const pid_t pid, char c);
void		split_into_chars(const pid_t pid, char *str);

#endif