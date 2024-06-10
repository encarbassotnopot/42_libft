/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/10 13:34:57 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_mem(int i, const void *(orig)(), const void *(mine)())
{
	unsigned int	errs;
	const size_t	allowed_size = 20;
	const size_t	max_size = 41;
	// 40 As, [41] = \0
	unsigned char	og_mem[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEAA";
	unsigned char	my_mem[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

	errs = 0;
	if (i == 0)
	{
		orig(og_mem, 40, allowed_size);
		mine(my_mem, 40, allowed_size);
		if (memcmp(my_mem, og_mem, max_size))
		{
			printf("ERROR!\n");
			printf("og mem: %s\n", og_mem);
			printf("my mem: %s\n", my_mem);
			errs++;
		}
	}
	return (errs);
}

int	main(void)
{
	int		errors;
	char	*names[] = {"ft_memset", "ft_bzero", "ft_memcpy", "ft_memmove",
			"ft_strlcpy", "ft_strlcat"};

	void (*orig[])() = {memset, bzero, memcpy, memmove /*, strlcpy, strlcat*/};
	void (*mine[])() = {ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_strlcpy,
		ft_strlcat};
	for (int i = 0; i < 6; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += test_mem(i, orig[i], mine[i]);
		printf("Done: %d errors found\n", errors);
	}
}
