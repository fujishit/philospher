/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:29:38 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 18:29:38 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wrap_sleep(long long sleep_time, t_philosopher *philo)
{
	long long	start;
	long long	now;

	(void)philo;
	get_msec(&start);
	get_msec(&now);
	while ((now - start) < sleep_time)
	{
		usleep(100);
		get_msec(&now);
	}
	return ;
}

void	*action_philo(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (philo->number % 2 == 0)
		wrap_sleep((philo->arg.time_to_eat / 2), philo);
	while (1)
	{
		pthread_mutex_lock(&table->dying);
		if (table->died == 1)
		{
			pthread_mutex_unlock(&table->dying);
			break ;
		}
		pthread_mutex_unlock(&table->dying);
		if (philo->mutex.right == philo->mutex.left)
			continue ;
		if (action_eat(philo) == 1)
			break ;
		if (action_sleep(philo) == 1)
			break ;
		if (action_think(philo) == 1)
			break ;
	}
	return (NULL);
}
