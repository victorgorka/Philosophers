/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:15:30 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/22 15:18:04 by vde-prad         ###   ########.fr       */
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
	data->n_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->n_lunches = ft_atoi(argv[5]);
	return (0);
}
