/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:39:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/31 16:25:23 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/**
 * This function returns the number of miliseconds that have passed from 1970 if
 * option == -1. If option is > 0, it returns the time that have passed between
 * option and the moment the function was called.
 * @param t pointer to time_t type variable
 * @param time struct where gettimeofday will write the info that it got
 * @return returns the number of miliseconds
*/
time_t	ft_time(time_t option)
{
	struct timeval	time;
	time_t			t;

	t = 0;
	gettimeofday(&time, 0);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (option == -1)
		return (t);
	else
		return (t - option);
}

/**
 * This function manages the suspension of the main or secundary 
 * threads.
 * @param t time in miliseconds or microseconds
 * @param option depending of the option value it takes the t variable
 * 				 as miliseconds or microseconds
 * @param start variable used as reference to calculate when to stop the
 * 				suspension
 * @param time variable of type timeval used to get the time in that moment
*/
void	ft_sleep(time_t t, int option)
{
	time_t			start;
	struct timeval	time;

	if (option == 2)
	{
		gettimeofday(&time, 0);
		start = time.tv_usec;
		t += start;
		while (start < t)
		{	
			usleep(100);
			gettimeofday(&time, 0);
			start = time.tv_usec;
		}
	}
	else
	{
		start = ft_time(-1);
		while (ft_time(start) < t)
			usleep(100);
	}
}

/**
 * Function that contains the rutine of the threads created
 * @param data struct with the necessary info
 * @param philos struct of the thread
 * @return NULL when the thread has finished
*/
static void	*philo(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	if (philos->index % 2 != 0)
		usleep(40);
	while (philos->n_lunches-- != 0)
	{
		if (ft_take_fork(philos))
			return (NULL);
		printf(FORK, ft_time(philos->stime), philos->index + 1);
		printf(EAT, ft_time(philos->stime), philos->index + 1);
		ft_sleep(philos->eat_time, 1);
		if (ft_inanition(philos))
		{
			pthread_mutex_unlock(&philos->fork1);
			pthread_mutex_unlock(philos->fork2);
			return (NULL);
		}
		pthread_mutex_lock(&philos->last_eat_mutex);
		philos->last_eat = ft_time(-1);
		pthread_mutex_unlock(&philos->last_eat_mutex);
		if (ft_drop_fork(philos))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (ft_input(argc, argv, &data) || ft_init_philosophers(&data))
		return (0);
	while (i < data.n_philo)
	{
		if (i % 2 != 0)
			ft_sleep(40, 2);
		data.stime = ft_time(-1);
		data.philos[i].last_eat = data.stime;
		data.philos[i].stime = data.stime;
		pthread_create(&data.philos[i].tid, NULL, philo, &data.philos[i]);
		i++;
	}
	while (1)
	{
		usleep(500);
		if (ft_check_finish(data.philos, data.n_philo))
			return (0);
		if (ft_check_philos(&data))
			return (0);
	}
	return (0);
}
