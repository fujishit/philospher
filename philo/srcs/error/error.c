/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:07 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 11:43:07 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	putstr_stderr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(2, str, len);
}

void	error_out(char *str)
{
	putstr_stderr("Error: ");
	if (str != NULL)
		putstr_stderr(str);
	else
		putstr_stderr("Undefined error");
	putstr_stderr("\n");
}
