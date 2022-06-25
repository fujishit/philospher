/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_msec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:05:38 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 18:05:38 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_msec(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 1)
		return (1);
	*time = (long long)tv.tv_sec * 1000;
	*time += (long long)tv.tv_usec / 1000;
	return (0);
}
