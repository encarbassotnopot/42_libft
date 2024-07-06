/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/06 10:39:11 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_str_size(unsigned int n, unsigned int radix)
{
	size_t	len;

	len = 2;
	while (n >= radix)
	{
		n /= radix;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned int n, const char *base)
{
	char	*out;
	size_t	radix;
	size_t	len;

	radix = ft_strlen(base);
	len = get_str_size(n, radix);
	out = ft_calloc(len, sizeof(char));
	if (!out)
		return (NULL);
	while (n != 0)
	{
		out[--len] = base[n % radix];
		n /= radix;
	}
	return (out);
}
