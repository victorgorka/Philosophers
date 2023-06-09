/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:15:30 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/31 15:30:58 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Initialization of the philosophers structures
 * @param data structure with basi info
 * @param i index iterator
 * @return return 1 if there is an error
*/
static int	ft_init(t_data *data)
{
	int				i;

	i = 0;
	data->philos = malloc(data->n_philo * sizeof(t_philo));
	if (!data->philos)
		return (1);
	while (i < data->n_philo)
	{
		data->philos[i].finish = 0;
		data->philos[i].index = i;
		data->philos[i].n_philo = data->n_philo;
		data->philos[i].die_time = data->die_time;
		data->philos[i].eat_time = data->eat_time;
		data->philos[i].sleep_time = data->sleep_time;
		data->philos[i++].n_lunches = data->n_lunches;
	}
	return (0);
}

/**
 * It initializes the mutexes used by the philosophers and
 * and assign the left fork to the philosophers
 * @param data struct with basi info
 * @param i index iterator
 * @return it returns 1 if there is an error
*/
int	ft_init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	if (ft_init(data))
		return (1);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->philos[i].fork1, NULL);
		pthread_mutex_init(&data->philos[i].finish_mutex, NULL);
		pthread_mutex_init(&data->philos[i++].last_eat_mutex, NULL);
	}
	while (--i >= 0)
	{
		if (data->n_philo == 1)
			data->philos[0].fork2 = NULL;
		else if (i + 1 == data->n_philo)
			data->philos[i].fork2 = &data->philos[0].fork1;
		else
			data->philos[i].fork2 = &data->philos[i + 1].fork1;
	}
	return (0);
}

/**
 * It checks the arguments passed to the program, and set the data
 * structure variables
 * @param argc number of arguments passed to the program
 * @param argv the arguments passed to the program
 * @param data structure with basic info for the program
 * @param i index iterator
 * @return it returns 1 if there is any error
*/
int	ft_input(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
		return (1);
	while (i < argc)
	{
		if (ft_check_args(argv[i++]))
			return (1);
	}
	data->n_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->n_lunches = -1;
	if (data->n_philo < 0 || data->die_time < 0 || data->eat_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (1);
	if (argc == 6)
	{
		data->n_lunches = ft_atoi(argv[5]);
		if (data->n_lunches < 0)
			return (1);
	}
	return (0);
}
