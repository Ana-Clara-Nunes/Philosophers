/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_appetit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:15:59 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 15:52:27 by anunes-o         ###   ########.fr       */
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
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
}

