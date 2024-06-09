/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/09 21:13:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		arr[n];
	const char	*my_src;
	char		*my_dest;

	my_src = src;
	my_dest = dest;
	i = 0;
	while (i < n)
	{
		arr[i] = my_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		my_dest[i] = arr[i];
		i++;
	}
	return (dest);
}
