/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:49:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/12/27 14:18:45 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if the given string is made up of only space charachters
 * (or an empty string). Returns 0 otherwise.
 */
int	ft_isspace_str(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isspace(s[i]))
			return (0);
	}
	return (1);
}
