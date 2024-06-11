/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:21:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/11 14:52:56 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr(char *s, int c)
{
	char *candidate = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			candidate = s;
		s++;
	}
	if (c == '\0')
		return (s);
	return ((char *)candidate);
}
