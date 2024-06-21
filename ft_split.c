/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:21:00 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 23:49:35 by ecoma-ba         ###   ########.fr       */
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

static unsigned int	**get_split_ends(char const *s, char c)
{
	unsigned int	**out;
	unsigned int	count;

	count = get_split_count(s, c) + 1;
	out = malloc(sizeof(void *) * 2);
	if (!out)
		return (NULL);
	out[0] = calloc(count + 1, sizeof(int));
	out[1] = calloc(count + 1, sizeof(int));
	if (!out[0] || !out [1])
		return (NULL);
	pop_splits(s, c, out);
	return (out);
}

static void	cleanup(unsigned int **ends, char **splits)
{
	unsigned int	i;

	i = 0;
	free(ends[0]);
	free(ends[1]);
	free(ends);
	if (splits)
	{
		while (splits[i])
			free(splits[i++]);
		free(splits);
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	**ends;
	unsigned int	i;
	char			**splits;

	if (!s)
		return (NULL);
	splits = calloc((get_split_count(s, c) + 1), sizeof(void *));
	ends = get_split_ends(s, c);
	if (!splits || !ends)
		return (NULL);
	i = 0;
	while (ends[0][i])
	{
		splits[i] = ft_substr(s, ends[0][i], ends[1][i]);
		if (!splits[i])
		{
			cleanup(ends, splits);
			return (NULL);
		}
		i++;
	}
	splits[i] = 0;
	cleanup(ends, NULL);
	return (splits);
}
