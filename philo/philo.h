/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:03 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/22 15:24:42 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**************** DEFINITIONS *****************/
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_data{
	struct timeval	time;
	time_t			stime;
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_lunches;
}	t_data;

/***************** FUNCTIONS ******************/

// init.c
void	ft_init(t_data *data);
int		ft_input(int argc, char **argv, t_data *data);
// utils.c
int		ft_atoi(const char *str);
int		ft_check_args(char *arg);

#endif