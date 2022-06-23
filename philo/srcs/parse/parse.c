/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:15 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 11:43:15 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_arg(int argc, char *argv[], t_arguments *arg)
{
	if (argc == 5 || argc == 6)
	{
		// このままだと0が通るので、修正が必要かも
		if (wrap_atoi(argv[1], &arg->number_of_philosophers) == 1)
			return (1);
		else if (wrap_atoi(argv[2], &arg->time_to_die) == 1)
			return (1);
		else if (wrap_atoi(argv[3], &arg->time_to_eat) == 1)
			return (1);
		else if (wrap_atoi(argv[4], &arg->time_to_sleep) == 1)
			return (1);
		else if (argc == 6 && wrap_atoi(\
			argv[5], &arg->number_of_times_each_philosopher_must_eat) == 1)
			return (1);
	}
	else
	{
		return (2);
	}
}
