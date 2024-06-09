/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:47:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/09 20:33:58 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;
	char	*my_ptr;

	i = 0;
	my_ptr = ptr;
	while (i < n)
	{
		my_ptr[i++] = c;
	}
	return (ptr);
}
