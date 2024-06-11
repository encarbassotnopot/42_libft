/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/10 16:05:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_mem(int i, const void *(orig)(), const void *(mine)(), size_t max_size)
{
	unsigned int	errs;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned char	og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcba\0                         ";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned char	my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcba\0                         ";

	errs = 0;
	printf("Max size is: %d\n", max_size);
	size_t og_out = orig(og_dst, og_mem, max_size);
	size_t my_out = mine(my_dst, my_mem, max_size);
	if (og_out != my_out)
	{
		printf("ERROR! Return value mismatched: og returns %d, mine returns %d\n",
				og_out, my_out);
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

int	main(void)
{
	int		errors;
	char	*names[] = {"ft_strlcpy", "ft_strlcat"};

	void (*mine[])() = {ft_strlcpy, ft_strlcat};
	void (*orig[])() = {strlcpy, strlcat};
	for (int i = 0; i < 2; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += test_mem(i, orig[i], mine[i], 0);
		errors += test_mem(i, orig[i], mine[i], 1);
		errors += test_mem(i, orig[i], mine[i], 6);
		errors += test_mem(i, orig[i], mine[i], 36);
		errors += test_mem(i, orig[i], mine[i], 60);
		errors += test_mem(i, orig[i], mine[i], 63);
		printf("Done: %d errors found\n", errors);
	}
}
