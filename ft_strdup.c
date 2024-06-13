/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:57:10 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 19:03:59 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	count;
	char	*dst;

	dst = malloc(ft_strlen(s));
	if (!dst)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		dst[count] = s[count];
		count++;
	}
	return (dst);
}
