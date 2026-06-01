/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:50:48 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 10:24:34 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	long			ms;
	struct timeval	time;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000L) + (time.tv_usec / 1000);
	return (ms);
}

long	get_lapse_time(long stamp)
{
	return (get_time() - stamp);
}

int	ft_usleep(long secs)
{
	long	start;
	long	curr;

	start = get_time();
	while (1)
	{
		curr = get_time();
		if (curr - start >= secs)
			break ;
		usleep(100);
	}
	return (0);
}
