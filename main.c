/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:48:00 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/29 12:36:48 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6)
		return (0);
	if (!parse_args(argv, &data))
		return (0);
	init_table(&data);
	if (!init_fork(&data))
	{
		// adicionar cleanup
		return (0);
	}
	if (!init_philo(&data))
	{
		// adicionar cleanup
		return (0);
	}
	return (0);
}
