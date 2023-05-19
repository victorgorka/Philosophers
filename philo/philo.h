/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:03 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/19 13:27:35 by vde-prad         ###   ########.fr       */
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
}	t_data;

/***************** FUNCTIONS ******************/

#endif