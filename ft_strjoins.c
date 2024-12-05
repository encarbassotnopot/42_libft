/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:25:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/12/05 10:19:54 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoins(unsigned int count, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;
	char	*merged;

	len = 1;
	i = -1;
	va_start(ap, count);
	while (++i < count)
		len += ft_strlen(va_arg(ap, char *));
	va_end(ap);
	merged = ft_calloc(len, sizeof(char));
	i = -1;
	va_start(ap, count);
	while (++i < count)
		ft_strlcat(merged, va_arg(ap, char *), len);
	va_end(ap);
	return (merged);
}
