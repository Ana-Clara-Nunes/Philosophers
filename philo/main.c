/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:48:00 by anunes-o          #+#    #+#             */
/*   Updated: 2026/06/02 16:16:18 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				routine, &data->philos[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6)
		return (0);
	if (!parse_args(argv, &data))
		return (0);
	init_table(&data);
	if (!init_forks(&data))
		return (cleanup_exit(&data));
	if (!init_philo(&data))
		return (cleanup_exit(&data));
	if (!start_simulation(&data))
		return (cleanup_exit(&data));
	monitor(&data);
	join_thread(&data);
	return (cleanup_exit(&data));
}
