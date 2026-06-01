/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:28:57 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 11:11:03 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_fork) * data->nb_philos);
	if (!(data->forks))
		return (0);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		i++;
	}
	return (1);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!(data->philos))
		return (0);
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		data->philos[i].data = data;
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
	return (1);
}

int	init_table(t_data *data)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->start_time = get_time();
	data->simulation_over = 0;
	return (1);
}

