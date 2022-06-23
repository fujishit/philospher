/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:19 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 11:43:19 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	show_arg(t_arguments arg)
{
	printf("number of philosophers: %d\n", arg.number_of_philosophers);
	printf("time to die: %d\n", arg.time_to_die);
	printf("time to eat: %d\n", arg.time_to_eat);
	printf("time to sleep: %d\n", arg.time_to_sleep);
	printf("number of philosophers: %d\n", \
	arg.number_of_times_each_philosopher_must_eat);
}

t_arguments	new_arg(void)
{
	t_arguments	new;

	new.number_of_philosophers = 0;
	new.time_to_die = 0;
	new.time_to_eat = 0;
	new.time_to_sleep = 0;
	new.number_of_times_each_philosopher_must_eat = 0;
	return (new);
}
