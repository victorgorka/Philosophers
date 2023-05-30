/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philochecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:42:39 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/30 21:11:27 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_kill_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philos[i].finish_mutex);
		data->philos[i].finish = 1;
		pthread_mutex_unlock(&data->philos[i].finish_mutex);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		pthread_join(data->philos[i++].tid, NULL);
}

int	ft_check_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philos[i].finish_mutex);
		pthread_mutex_lock(&data->philos[i].last_eat_mutex);
		if (data->philos[i].finish != 2
			&& ft_time(-1) - data->philos[i].last_eat >= data->die_time)
		{
			pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
			pthread_mutex_unlock(&data->philos[i].finish_mutex);
			printf("%ld ms %d has died\n",
				ft_time(data->philos[i].stime), i + 1);
			ft_kill_join(data);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].finish_mutex);
		pthread_mutex_unlock(&data->philos[i++].last_eat_mutex);
	}
	return (0);
}

int	ft_check_finish(t_philo *philos, int n_philos)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_lock(&philos[i].finish_mutex);
		if (philos[i].finish != 2)
			check = 0;
		else
			pthread_detach(philos[i].tid);
		pthread_mutex_unlock(&philos[i].finish_mutex);
		i++;
	}
	return (check);
}
