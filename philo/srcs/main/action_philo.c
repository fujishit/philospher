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

void	*action_philo(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (philo->number % 2 == 0)
		usleep(table->arg.time_to_eat);
	while (table->died != 1)
	{
		action_eat(philo);
		if (table->died == 1)
			break ;
		action_sleep(philo);
		if (table->died == 1)
			break ;
		action_think(philo);
	}
	return (NULL);
}
