/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:21:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:51:00 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*candidate;

	if (!s)
		return (NULL);
	candidate = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			candidate = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (candidate);
}
