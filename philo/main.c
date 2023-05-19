/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:39:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/19 20:33:57 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_data *data)
{
	data->n_philo = -1;
	data->die_time = -1;
	data->eat_time = -1;
	data->sleep_time = -1;
	data->n_lunches = -1;
	gettimeofday(&data->time, 0);
	data->stime = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
}

int	ft_time(t_data *data)
{
	int	ms;

	ms = 0;
	gettimeofday(&data->time, 0);
	ms = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
	return (ms - data->stime);
}

int	ft_check_args(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_input(int argc, char **argv, t_data *data)
{
	int	i;

	(void)data;
	i = 1;
	if (argc > 6 || argc < 5)
		return (1);
	while (i < argc)
	{
		if (ft_check_args(argv[i++]))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (ft_input(argc, argv, &data))
		return (1);
	ft_init(&data);
	while (1)
		printf("%d ms\n", ft_time(&data));
	return (0);
}
