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

static void	print_sleeping(\
	int died, int number, long long start_time, pthread_mutex_t *printing)
{
	long long	now;

	get_msec(&now);
	pthread_mutex_lock(printing);
	if (died != 1)
		printf("%lld %d is sleeping\n", (now - start_time), number);
	pthread_mutex_unlock(printing);
}

void	action_sleep(t_philosopher *philo)
{
	if (philo->table->died == 1)
		return ;
	print_sleeping(philo->table->died, philo->number, \
						philo->table->start_time, philo->mutex.printing);
	if (philo->table->died == 1)
		return ;
	usleep(philo->arg.time_to_sleep * 1000);
}