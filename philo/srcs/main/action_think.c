/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:38:01 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 22:38:01 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	print_thinking(t_philosopher *philo, t_table *table)
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
		printf("%lld %d is thinking\n", (now - start_time), philo->number);
		pthread_mutex_unlock(&table->printing);
		return (0);
	}
	return (0);
}

int	action_think(t_philosopher *philo)
{
	if (print_thinking(philo, philo->table) == 1)
		return (1);
	return (0);
}
