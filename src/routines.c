/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:49:54 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 16:12:39 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *) arg);
	while (!is_simulation_over(philo->data))
	{
		take_forks(philo);
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	sleep(t_philo	*philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	think(t_philo	*philo)
{
	print_action(philo, "is thinking");
}

int	is_simulation_over(t_data *data)
{
	int	save;

	pthread_mutex_lock(&data->death_mutex);
	save = data->simulation_over;
	pthread_mutex_unlock(&data->death_mutex);
	return (save);
}

void	print_action(t_philo *philo, char *action)
{
	if (is_simulation_over(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("[%ld] %d %s\n", get_lapse_time(philo->data->start_time),
		philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
