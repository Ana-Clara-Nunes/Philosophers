/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:49:54 by anunes-o          #+#    #+#             */
/*   Updated: 2026/06/02 16:30:08 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *) arg);
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		return (NULL);
	}
	while (!is_simulation_over(philo->data))
	{
		take_forks(philo);
		eat(philo);
		to_sleep(philo);
		to_think(philo);
	}
	return (NULL);
}

void	to_sleep(t_philo	*philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	to_think(t_philo	*philo)
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
