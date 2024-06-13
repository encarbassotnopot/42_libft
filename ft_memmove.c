/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 18:20:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*my_src;
	char		*my_dest;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	my_src = src;
	my_dest = dest;
	i = 0;
	while (n-- > 0)
	{
		my_dest[n] = my_src[n];
	}
	return (dest);
}
