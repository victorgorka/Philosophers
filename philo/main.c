/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:39:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/19 15:37:09 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_data *data)
{
	gettimeofday(&data->time, 0);
	data->stime = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
}

int	ft_time(t_data *data)
{
	int	ms;

	ms = 0;
	gettimeofday(&data->time, 0);
	ms = data->time.tv_sec * 1000 + (data->time.tv_usec / 1000);
	return (ms - data->stime);
}

int	main(void)
{
	t_data			data;

	ft_init(&data);
	while (1)
		printf("%d ms\n", ft_time(&data));
}
