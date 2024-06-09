/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_isx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:24:19 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/09 19:22:09 by ecoma-ba         ###   ########.fr       */
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

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_sign(int start, int end, int (*orig)(int),
		int (*mine)(int))
{
	unsigned int	count;
	int				orig_ret;
	int				mine_ret;

	count = 0;
	if (start > end)
		return (-1);
	for (int i = start; i <= end; i++)
	{
		orig_ret = get_sign(orig(i));
		mine_ret = get_sign(mine(i));
		if (orig_ret != mine_ret)
		{
			printf("MISMATCH with value %d!: orig is %d, mine is %d\n", i,
				orig_ret, mine_ret);
			count++;
		}
	}
	return (count);
}

int	main()
{
	int	oks;

	int (*orig[5])(int) = {isalpha, isdigit, isascii, isprint, isalnum};
	int (*mine[5])(int) = {ft_isalpha, ft_isdigit, ft_isascii, ft_isprint,
		ft_isalnum};
	char *names[5] = {"ft_isalpha", "ft_isdigit", "ft_isascii", "ft_isprint",
		"ft_isalnum"};
	for (int i = 0; i < 5; i++)
	{
		printf("Now testing function %s\n", names[i]);
		oks += test_sign(0, 128, orig[i], mine[i]);
		printf("Done: %d errors found\n", oks);
	}
}
