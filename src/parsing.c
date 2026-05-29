/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:14:21 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 14:34:11 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *nb)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while ((nb[i] >= '0' && nb[i] <= '9'))
	{
		if (result > INT_MAX / 10)
			return (-1);
		result = result * 10 +(nb[i] - '0');
		i++;
	}
	return (result);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_digit(argv[i]))
			return (0);
		i++;
	}
	data->nb_philos = ft_atoi(argv[1]);
	data->time_to_die = (long)ft_atoi(argv[2]);
	data->time_to_eat = (long)ft_atoi(argv[3]);
	data->time_to_sleep = (long)ft_atoi(argv[4]);
	if (argv[5])
	{
		data->must_eat_count = ft_atoi(argv[5]);
		if (!(data->must_eat_count >= 1))
			return (0);
	}
	else
		data->must_eat_count = -1;
	if (!(data->nb_philos >= 1 && data->time_to_die >= 1
			&& data->time_to_eat >= 1 && data->time_to_sleep >= 1))
		return (0);
	return (1);
}
