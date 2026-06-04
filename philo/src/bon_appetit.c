/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_appetit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:15:59 by anunes-o          #+#    #+#             */
/*   Updated: 2026/06/04 16:30:07 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_action(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
}

void	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
}

int	satisfied_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->death_mutex);
	while (i < data->nb_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat_count)
		{
			pthread_mutex_unlock(&data->death_mutex);
			return (0);
		}
		i++;
	}	
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}
