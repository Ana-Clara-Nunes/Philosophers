/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:08 by anunes-o          #+#    #+#             */
/*   Updated: 2026/06/01 15:01:51 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data)
{
	int		i;
	long	last_meal;

	while (!is_simulation_over(data))
	{
		i = 0;
		while (i < data->nb_philos)
		{
			last_meal = save_meal(data, i);
			if (get_lapse_time(last_meal) >= data->time_to_die)
			{
				print_action(&data->philos[i], "died");
				pthread_mutex_lock(&data->death_mutex);
				data->simulation_over = 1;
				pthread_mutex_unlock(&data->death_mutex);
			}
			if (data->must_eat_count == -1)
				break ;
			if (satisfied_philos(data))
			{
				pthread_mutex_lock(&data->death_mutex);
				data->simulation_over = 1;
				pthread_mutex_unlock(&data->death_mutex);
			}
			i++;
		}
	}
}

long	save_meal(t_data *data, int i)
{
	long	meal;

	pthread_mutex_lock(&data->death_mutex);
	meal = data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->death_mutex);
	return (meal);
}

int	satisfied_philos(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->philos[i].meals_eaten == data->must_eat_count)
			check++;
		i++;
		pthread_mutex_unlock(&data->death_mutex);
	}
	if (check == data->nb_philos)
		return (1);
	return (0);
}
