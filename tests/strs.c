/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/10 15:44:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_mem(int i, const void *(orig)(), const void *(mine)())
{
	unsigned int	errs;
	const size_t	allowed_size = 20;
	const size_t	max_size = 63;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

	// 40 As, [41] = \0
	errs = 0;
	if (i == 0)
	{
		orig(og_mem, 40, allowed_size);
		mine(my_mem, 40, allowed_size);
	}
	else if (i == 1)
	{
		orig(og_mem, allowed_size);
		mine(my_mem, allowed_size);
	}
	else if (i < 4)
	{
		orig(og_dst, og_mem, allowed_size);
		mine(my_dst, my_mem, allowed_size);
	}
	if (memcmp(my_mem, og_mem, max_size))
	{
		printf("ERROR!\n");
		errs++;
	}
	printf("og mem: %.63s\n", og_mem);
	printf("my mem: %.63s\n", my_mem);
	if (memcmp(my_dst, og_dst, max_size))
	{
		printf("ERROR!\n");
		errs++;
	}
	printf("og dst: %.63s\n", og_dst);
	printf("my dst: %.63s\n", my_dst);
	return (errs);
}

int	main(void)
{
	int		errors;
	char	*names[] = {"ft_memset", "ft_bzero", "ft_memcpy", "ft_memmove"};

	void (*mine[])() = {ft_memset, ft_bzero, ft_memcpy,
		ft_strlcat};
	void (*orig[])() = {memset, bzero, memcpy, memmove};
	for (int i = 0; i < 4; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += test_mem(i, orig[i], mine[i]);
		printf("Done: %d errors found\n", errors);
	}
}
