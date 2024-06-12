/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_isx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:24:19 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/12 13:06:15 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

// returns 1 if i is positive, -1 if negative, 0 if 0
int	get_sign(int i)
{
	if (i > 0)
		return (1);
	if (i < 0)
		return (-1);
	return (0);
}

// returns the same int
int	do_nothing(int i)
{
	return (i);
}

// tests a custom implementation of a function against the original one
// returns count of mismatched returns. applies the given transformation
// to the return value before comparing.
int	test_sign(int start, int end, int (*orig)(int),
		int (*mine)(int), int (*trans)(int))
{
	int	count;
	int	orig_ret;
	int	mine_ret;

	count = 0;
	if (start > end)
		return (-1);
	for (int i = start; i <= end; i++)
	{
		orig_ret = trans(orig(i));
		mine_ret = trans(mine(i));
		if (orig_ret != mine_ret)
		{
			printf("MISMATCH with value %d!: orig is %d, mine is %d\n", i,
				orig_ret, mine_ret);
			count++;
		}
	}
	return (count);
}

int	main(void)
{
	int	oks;

	int (*orig[])(int) = {isalpha, isdigit, isascii, isprint, isalnum, toupper,
		tolower};
	int (*mine[])(int) = {ft_isalpha, ft_isdigit, ft_isascii, ft_isprint,
		ft_isalnum, ft_toupper, ft_tolower};
	int (*trans[])(int) = {get_sign, get_sign, get_sign, get_sign, get_sign,
		do_nothing, do_nothing};
	char *names[] = {"ft_isalpha", "ft_isdigit", "ft_isascii", "ft_isprint",
		"ft_isalnum", "ft_toupper", "ft_tolower"};
	for (int i = 0; i < 7; i++)
	{
		printf("Now testing function %s\n", names[i]);
		oks = test_sign(-10, 140, orig[i], mine[i], trans[i]);
		printf("Done: %d errors found\n", oks);
	}
}
