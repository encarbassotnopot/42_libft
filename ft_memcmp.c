/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/12 12:45:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	index;
	const char		*my_s1;
	const char		*my_s2;

	my_s1 = s1;
	my_s2 = s2;
	index = 0;
	while (index < n)
	{
		if (my_s1[index] != my_s2[index])
		{
			return (my_s1[index] - my_s2[index]);
		}
		index++;
	}
	return (0);
}
