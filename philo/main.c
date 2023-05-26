/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:39:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/26 21:53:39 by vde-prad         ###   ########.fr       */
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
int	ft_time(int option)
{
	struct timeval	time;
	time_t			t;

	t = 0;
	gettimeofday(&time, 0);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (option < 0)
		return (t);
	else
		return (t - option);
}

int	ft_inanition(t_philo *philos)
{
	pthread_mutex_lock(&philos->finish_mutex);
	if (philos->finish)
		return (1);
	pthread_mutex_unlock(&philos->finish_mutex);
	return (0);
}

void	*rutina(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	while (philos->n_lunches-- != 0)
	{
		pthread_mutex_lock(&philos->fork1);
		if (ft_inanition(philos))
			return (NULL);
		printf("%d ms %d has taken fork 1\n", ft_time(philos->stime), philos->index + 1);
		if (philos->fork2 != NULL)
			pthread_mutex_lock(philos->fork2);
		else
			usleep(philos->die_time * 1000);
		if (ft_inanition(philos))
			return (NULL);
		printf("%d ms %d has taken fork 2\n", ft_time(philos->stime), philos->index + 1);
		printf("%d ms %d is eating\n", ft_time(philos->stime),
			philos->index + 1);
		usleep(philos->eat_time * 1000);
		if (ft_inanition(philos))
			return (NULL);
		philos->last_eat = ft_time(-1);
		pthread_mutex_unlock(&philos->fork1);
		pthread_mutex_unlock(philos->fork2);
		printf("%d ms %d is sleeping\n", ft_time(philos->stime), philos->index + 1);
		usleep(philos->sleep_time * 1000);
		if (ft_inanition(philos))
			return (NULL);
		printf("%d ms %d is thinking\n", ft_time(philos->stime), philos->index + 1);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.n_lunches = -1;
	if (ft_input(argc, argv, &data) || ft_init_philosophers(&data))
		return (1);
	while (i < data.n_philo)
	{
		if (i % 2 != 0)
			usleep(50);
		pthread_create(&data.philos[i].tid, NULL, rutina, &data.philos[i]);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < data.n_philo)
		{
			if (ft_time(-1) - data.philos[i].last_eat > data.die_time)
			{
				// printf("last eat off dead philo %ld\n", data.philos[i].last_eat);
				printf("%d ms %d has died\n", ft_time(data.stime), i + 1);
				i = 0;
				while (i < data.n_philo)
				{
					pthread_mutex_lock(&data.philos[i].finish_mutex);
					data.philos[i++].finish = 1;
					pthread_mutex_unlock(&data.philos[i].finish_mutex);
				}
				i = 0;
				while (i < data.n_philo)
					pthread_join(data.philos[i++].tid, NULL);
				return (0);
			}
		}
	}
	return (0);
}
