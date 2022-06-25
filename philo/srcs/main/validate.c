/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:17:19 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 17:17:19 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_invalid_number(void)
{
	error_out("Validate: Invalid number");
	return (1);
}

int	validate_arg(t_arguments *arg)
{
	if (arg->number_of_philosophers <= 0)
		return (error_invalid_number());
	else if (arg->time_to_die <= 0)
		return (error_invalid_number());
	else if (arg->time_to_eat <= 0)
		return (error_invalid_number());
	else if (arg->time_to_sleep <= 0)
		return (error_invalid_number());
	else if (arg->number_of_times_each_philosopher_must_eat <= 0)
		return (error_invalid_number());
	return (0);
}
