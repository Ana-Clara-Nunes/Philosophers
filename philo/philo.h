/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:11:47 by anunes-o          #+#    #+#             */
/*   Updated: 2026/05/27 13:11:47 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
//*                             STANDART LIBRARIES                            */
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/* ************************************************************************** */
/* 	                              STRUCTS                                     */
/*       S_FORK - REPRESENTS A PHYSICAL FORK                                  */
/*       S_DATA - THE SIMULATION GLOBAL DATA (TABLE)                          */
/*       S_PHILO - REPRESENTS A PHILOSOPHER                                   */
/* ************************************************************************** */
typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	int					nb_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					must_eat_count;
	long				start_time;
	int					simulation_over;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	t_fork				*forks;
	struct s_philo		*philos;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	long		last_meal_time;
	int			meals_eaten;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
}	t_philo;

/* ************************************************************************** */
//*        - Function declarations and their respective .c files -    	      */
/* ************************************************************************** */
// * parsing.c
int		parse_args(char **argv, t_data *data);

// * time_utils.c
long	get_time(void);
int		ft_usleep(long secs);
long	get_lapse_time(long stamp);

// * bon_appetite.c
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
int		satisfied_philos(t_data *data);

// *routines.c
void	print_action(t_philo *philo, char *action);
int		is_simulation_over(t_data *data);
void	*routine(void *arg);
void	to_sleep(t_philo	*philo);
void	to_think(t_philo	*philo);

// * cleanup.c
int		cleanup_exit(t_data *data);
void	cleanup(t_data *data);

// * init.c
int		init_forks(t_data *data);
int		init_philo(t_data *data);
int		init_table(t_data *data);

// * monitor.c
void	monitor(t_data *data);
int		satisfied_philos(t_data *data);
long	save_meal(t_data *data, int i);
void	print_death(t_data *data, int id);
void	print_all_eat(t_data *data);

#endif