/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:56:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:51:51 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*src;
	char			*dst;
	unsigned int	i;

	if (!s)
		return (NULL);
	src = (char *)s;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (*src != '\0' && i++ < start)
		src++;
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
