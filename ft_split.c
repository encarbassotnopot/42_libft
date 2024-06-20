/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:21:00 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/20 19:21:16 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	get_split_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	in_delim;
	unsigned int	count;

	i = 0;
	in_delim = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (in_delim)
				count++;
			in_delim = 0;
		}
		else
		{
			in_delim = 1;
		}
		i++;
	}
	return (count);
}

static void	pop_splits(char const *s, char c, unsigned int **out)
{
	unsigned int	i;
	unsigned int	in_delim;
	unsigned int	found;

	i = 0;
	in_delim = 1;
	found = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (in_delim)
				out[0][found] = i;
			in_delim = 0;
		}
		else if (!in_delim)
		{
			in_delim = 1;
			out[1][found] = i - out[0][found];
			found++;
		}
		i++;
	}
	if (out[1][found] == 0)
		out[1][found] = i - out[0][found];
}

static unsigned int	**get_split_ends(char const *s, char c, unsigned int count)
{
	unsigned int	**out;

	out = malloc(sizeof(void *) * 2);
	out[0] = malloc(sizeof(void *) * count);
	out[1] = malloc(sizeof(void *) * count);
	ft_bzero(out[0], sizeof(void *) * count);
	ft_bzero(out[1], sizeof(void *) * count);
	pop_splits(s, c, out);
	return (out);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	**ends;
	unsigned int	i;
	char			**splits;

	count = get_split_count(s, c);
	splits = malloc(sizeof(void *) * (count + 1));
	if (!splits)
		return (NULL);
	ends = get_split_ends(s, c, count);
	i = 0;
	while (i < count)
	{
		splits[i] = ft_substr(s, ends[0][i], ends[1][i]);
		i++;
	}
	splits[i] = 0;
	free(ends[0]);
	free(ends[1]);
	free(ends);
	return (splits);
}
