/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:25:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/12/05 10:19:19 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_concatenate(char **strs)
{
	size_t	len;
	size_t	i;
	char	*merged;

	len = 1;
	i = -1;
	while (strs[++i])
		len += ft_strlen(strs[i]);
	merged = ft_calloc(len, sizeof(char));
	i = -1;
	while (strs[++i])
		ft_strlcat(merged, strs[i], len);
	return (merged);
}
