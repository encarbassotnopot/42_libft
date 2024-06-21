/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:21:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:43:22 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*my_str;

	if (!s)
		return (NULL);
	my_str = (char *)s;
	while (*my_str != c)
	{
		if (*my_str == '\0')
			return (NULL);
		my_str++;
	}
	return (my_str);
}
