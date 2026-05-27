/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:28:57 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/27 15:50:34 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_fork) * data->nb_philos);
	if (!(data->forks))
		return (1);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		i++;
	}
	return(0);
}