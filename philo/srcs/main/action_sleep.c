/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:13:58 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 22:13:58 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	print_sleeping(t_philosopher *philo, t_table *table)
{
	long long	now;
	long long	start_time;

	get_msec(&now);
	start_time = table->start_time;
	pthread_mutex_lock(&table->dying);
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->dying);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&table->dying);
		pthread_mutex_lock(&table->printing);
		printf("%lld %d is sleeping\n", (now - start_time), philo->number);
		pthread_mutex_unlock(&table->printing);
		return (0);
	}
	return (0);
}

int	action_sleep(t_philosopher *philo)
{
	if (print_sleeping(philo, philo->table) == 1)
		return (1);
	wrap_sleep(philo->arg.time_to_sleep, philo);
	return (0);
}
