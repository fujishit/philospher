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

void	wrap_sleep(long long sleep_time)
{
	long long	start;
	long long	now;

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
		wrap_sleep((philo->arg.time_to_eat / 2));
	while (table->died == 0)
	{
		if (action_eat(philo) == 1)
			break ;
		wrap_sleep(table->arg.time_to_sleep);
		// action_sleep(philo);
		// printf("think\n");
		// action_think(philo);
		// printf("end\n");
	}
	// pthread_mutex_unlock(&table->dying);
	return (NULL);
}
