/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:39:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/22 15:31:50 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time(t_data *data)
{
	int	ms;

	ms = 0;
	gettimeofday(&data->time, 0);
	ms = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
	return (ms - data->stime);
}

int	main(int argc, char **argv)
{
	t_data			data;

	ft_init(&data);
	if (ft_input(argc, argv, &data))
		return (1);
	printf("%d\n", data.n_philo);
	printf("%d\n", data.die_time);
	printf("%d\n", data.eat_time);
	printf("%d\n", data.sleep_time);
	printf("%d\n", data.n_lunches);
	return (0);
}
