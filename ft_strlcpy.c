/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:27:59 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:47:16 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	if (!dst || !src)
		return (0);
	count = 0;
	while (src[count] != '\0' || count < size)
	{
		if (count < size)
		{
			dst[count] = src[count];
		}
		else if (count == size && size != 0)
		{
			dst[count - 1] = '\0';
		}
		if (src[count] == '\0')
		{
			dst[count] = src[count];
			return (count);
		}
		count++;
	}
	return (count);
}
