/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:51:25 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 16:47:30 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*my_s;

	my_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if (my_s[i] == c)
		{
			return ((&my_s[i]));
		}
		i++;
	}
	return(NULL);
}
