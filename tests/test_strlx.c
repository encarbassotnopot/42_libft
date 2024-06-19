/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 13:32:08 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
static unsigned int	test_mem(size_t (*orig)(char *, const char *, size_t),
		size_t (*mine)(char *, const char *, size_t), size_t max_size)
{
	unsigned int	errs;
	size_t			og_out;
	size_t			my_out;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned char	og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcba\0                         ";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned char	my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcba\0                         ";

	errs = 0;
	printf("Max size is: %ld\n", max_size);
	og_out = orig(og_dst, og_mem, max_size);
	my_out = mine(my_dst, my_mem, max_size);
	if (og_out != my_out)
	{
		printf("ERROR! Return value mismatched: og returns %ld, mine returns"
			"%ld\n", og_out, my_out);
		errs++;
	}
	if (memcmp(my_dst, og_dst, max_size))
	{
		printf("ERROR! Memory mismatch\n");
		errs++;
	}
	printf("og dst: %.63s\n", og_dst);
	printf("my dst: %.63s\n", my_dst);
	return (errs);
}

unsigned int	test_strlx(void)
{
	unsigned int	errors;
	unsigned int	total_errors;
	char			*names[] = {"ft_strlcpy", "ft_strlcat"};

	total_errors = 0;
	size_t (*mine[])(char *, const char *, size_t) = {ft_strlcpy, ft_strlcat};
	size_t (*orig[])(char *, const char *, size_t) = {strlcpy, strlcat};
	for (int i = 0; i < 2; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += test_mem(orig[i], mine[i], 0);
		errors += test_mem(orig[i], mine[i], 1);
		errors += test_mem(orig[i], mine[i], 6);
		errors += test_mem(orig[i], mine[i], 36);
		errors += test_mem(orig[i], mine[i], 60);
		errors += test_mem(orig[i], mine[i], 63);
		printf("Done: %d errors found\n", errors);
		total_errors +=	errors;
	}
	return (total_errors);
}
