/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:03 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/29 17:07:42 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/***************** INCLUDES *******************/
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

/**************** DEFINITIONS *****************/
typedef struct s_philo{
	pthread_t		tid;
	pthread_mutex_t	fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t last_eat_mutex;
	time_t			last_eat;
	time_t			stime;
	int				index;
	int				finish;
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_lunches;
}	t_philo;

typedef struct s_data{
	time_t			stime;
	t_philo			*philos;
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_lunches;
}	t_data;

/***************** FUNCTIONS ******************/

// init.c
int		ft_input(int argc, char **argv, t_data *data);
int		ft_init_philosophers(t_data *data);
// utils.c
int		ft_atoi(const char *str);
int		ft_check_args(char *arg);

#endif