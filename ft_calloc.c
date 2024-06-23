/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:48:18 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 13:16:43 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*out;

	if (SIZE_MAX / nmemb < size)
		return (NULL);
	total = nmemb * size;
	out = malloc(total);
	if (!out)
		return (NULL);
	ft_bzero(out, total);
	return (out);
}
