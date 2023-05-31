/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:40:48 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/31 15:48:36 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * It checks if there is only one philospher. If thats is the case, he could
 * never take the fork and will die of inanition
*/
static int	ft_only_one(t_philo *philos)
{
	if (philos->fork2 != NULL)
		pthread_mutex_lock(philos->fork2);
	else
	{
		pthread_mutex_unlock(&philos->fork1);
		while (1)
		{
			usleep(500);
			if (ft_inanition(philos))
				return (1);
		}
	}
	return (0);
}

/**
 * It let the philosopher to take the forks if its available, and checks if
 * the philosopher have died of inanition
 * @return 1 if the thread have to terminate
*/
int	ft_take_fork(t_philo *philos)
{
	pthread_mutex_lock(&philos->fork1);
	if (ft_inanition(philos))
	{
		pthread_mutex_unlock(&philos->fork1);
		return (1);
	}
	printf(FORK, ft_time(philos->stime), philos->index + 1);
	if (ft_only_one(philos))
		return (1);
	if (ft_inanition(philos))
	{
		pthread_mutex_unlock(&philos->fork1);
		pthread_mutex_unlock(philos->fork2);
		return (1);
	}
	return (0);
}

/**
 * It make the philosphers to drop the forks and check if its the last lunch
 * the philo has.
 * @return 1 if the thread have termiate
*/
int	ft_drop_fork(t_philo *philos)
{
	pthread_mutex_unlock(&philos->fork1);
	pthread_mutex_unlock(philos->fork2);
	if (philos->n_lunches == 0)
	{
		pthread_mutex_lock(&philos->finish_mutex);
		philos->finish = 2;
		pthread_mutex_unlock(&philos->finish_mutex);
		return (1);
	}
	printf(SLEEP, ft_time(philos->stime), philos->index + 1);
	ft_sleep(philos->sleep_time, 1);
	if (ft_inanition(philos))
		return (1);
	printf(THINK, ft_time(philos->stime), philos->index + 1);
	return (0);
}

/**
 * It checks if the philo have died of inanition
 * @return 1 if the philo have died
*/
int	ft_inanition(t_philo *philos)
{
	pthread_mutex_lock(&philos->finish_mutex);
	if (philos->finish == 1)
	{
		pthread_mutex_unlock(&philos->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philos->finish_mutex);
	return (0);
}
