/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:17:23 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 17:17:23 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philosopher	new_philosopher(void)
{
	t_philosopher	philo;

	philo.number = 0;
	philo.last_eat_time = 0;
	philo.eat_count = 0;
	return (philo);
}

int	delete_philosopher(t_philosopher *philos)
{
	free(philos);
	return (0);
}
