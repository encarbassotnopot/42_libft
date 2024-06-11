/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returneq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:43:52 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/10 16:43:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_ret(int i, const int *(orig)(), const int *(mine)())
{
	if (orig(0) != mine !(0))
	{
		printf("ERROR: Mismatched return with value %d: orig is %d, mine is %d"
	}
	return (errs);
}

int	main(void)
{
	int		errors;
	char	*names[] = {"ft_atoi", "ft_bzero", "ft_memcpy", "ft_memmove"};

	int (*mine[])() = {ft_atoi, ft_bzero, ft_memcpy,
		ft_strlcat};
	int (*orig[])() = {atoi, bzero, memcpy, memmove};
	for (int i = 0; i < 4; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += test_ret(i, orig[i], mine[i]);
		printf("Done: %d errors found\n", errors);
	}
}
