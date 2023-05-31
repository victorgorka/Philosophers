/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:44:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/31 15:33:57 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * It checks the sign of the number
*/
static int	ft_check_sign(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

/**
 * It transforms a string to int
 * @return -1 if there is any error
*/
int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r' )
		str++;
	if (*str == '-' || *str == '+')
		sign = ft_check_sign ((char *)str++);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if (res != (int) res)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return ((int) res);
}

/**
 * It check the arguments passed to the program
 * @return 1 if there is any error
*/
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

/**
 * It free all the memory in the structure
*/
void	ft_free(t_philo *philos)
{
	int	n;
	int	i;

	n = philos[0].n_philo;
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&philos[i].fork1);
		pthread_mutex_destroy(&philos[i].finish_mutex);
		pthread_mutex_destroy(&philos[i].last_eat_mutex);
		i++;
	}
	free(philos);
}
