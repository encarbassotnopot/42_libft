/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raw_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:06:37 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 12:36:19 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

unsigned int	ft_raw_atoi(const char *str)
{
	unsigned int	result;
	char			*my_str;

	if (!str)
		return (0);
	my_str = (char *)str;
	result = 0;
	while (*my_str >= '0' && *my_str <= '9')
	{
		result *= 10;
		result += *my_str - '0';
		my_str++;
	}
	return (result);
}
