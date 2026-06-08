/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:08 by anunes-o          #+#    #+#             */
/*   Updated: 2026/06/08 14:47:10 by anunes-o         ###   ########.fr       */
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
			if (get_lapse_time(last_meal) > data->time_to_die)
			{
				print_death(data, data->philos[i].id);
				return ;
			}
			if (data->must_eat_count != -1 && satisfied_philos(data))
			{
				print_all_eat(data);
				return ;
			}
			i++;
			usleep(100);
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

void	print_death(t_data *data, int id)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_over = 1;
	pthread_mutex_lock(&data->print_mutex);
	printf("[%ld] %d died\n", get_lapse_time(data->start_time), id);
	pthread_mutex_unlock(&data->print_mutex);
}

void	print_all_eat(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_over = 1;
	printf("[%ld] All philosophers have eaten %d times\n",
		get_lapse_time(data->start_time), data->must_eat_count);
	pthread_mutex_unlock(&data->print_mutex);
}
