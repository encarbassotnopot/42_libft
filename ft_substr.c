/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:56:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 13:51:02 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*src;
	char			*dst;
	unsigned int	i;

	src = (char *)s;
	dst = malloc(len);
	if (!dst || len == 0)
		return (NULL);
	i = 0;
	while (*src != '\0' && i++ < start)
		src++;
	i = 0;
	while (src[i] != '\0' && i + 1 < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
