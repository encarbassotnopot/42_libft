/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/12 13:08:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

unsigned int	compare_outs(size_t orig, size_t mine)
{
	if (og_out != my_out)
	{
		printf("ERROR! Return value mismatched: og returns %d, mine returns
			%d\n", og_out, my_out);
		return (1);
	}
	return (0);
}

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	run_test(int i, const void (*orig)(), const void (*mine)())
{
	unsigned int	errs;
	size_t			og_out;
	size_t			my_out;
	unsigned char	**mem;

	mem = malloc(sizeof(void) * 4);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	mem[3] = "ABCDEFGHIJK\0MNOPQRSTUVWXYZ";
	errs = 0;
	// memchr
	if (i == 0)
	{
		errs += compare_outs(orig(mem[0], 'B', 27), mine(mem[0], 'B', 27));
		errs += compare_outs(orig(mem[0], 'b', 27), mine(mem[0], 'b', 27));
		errs += compare_outs(orig(mem[2], 'Q', 10), mine(mem[2], 'Q', 10));
		errs += compare_outs(orig(mem[2], 'Q', 27), mine(mem[2], 'Q', 27));
		errs += compare_outs(orig(mem[2], 'q', 27), mine(mem[2], 'q', 27));
	}
	// strchr/strrchr
	else if (i == 1 || i == 2)
	{
		errs += compare_outs(orig(mem[0], 'B'), mine(mem[0], 'B'));
		errs += compare_outs(orig(mem[0], 'b'), mine(mem[0], 'b'));
		errs += compare_outs(orig(mem[2], 'Q'), mine(mem[2], 'Q'));
		errs += compare_outs(orig(mem[2], 'q'), mine(mem[2], 'q'));
	}
	// memcmp/strncmp
	else if (i == 3 || i == 4)
	{
		errs += compare_outs(orig(mem[0], mem[0], 10), mine(mem[0], mem[0],
				10));
		errs += compare_outs(orig(mem[0], mem[1], 10), mine(mem[0], mem[1],
				10));
		errs += compare_outs(orig(mem[0], mem[1], 27), mine(mem[0], mem[1],
				27));
		errs += compare_outs(orig(mem[1], mem[2], 27), mine(mem[1], mem[2],
				27));
		errs += compare_outs(orig(mem[1], mem[2], 27), mine(mem[1], mem[2],
				10));
	}
	// strnstr
	else if (i == 5)
	{
		errs += compare_outs(orig(mem[0], "DEF"), mine(mem[0], "DEF"));
		errs += compare_outs(orig(mem[0], "DEf"), mine(mem[0], "DEf"));
		errs += compare_outs(orig(mem[0], "123"), mine(mem[0], "123"));
		errs += compare_outs(orig("123", mem[0]), mine("123", mem[0]));
	}
	// atoi
	else if (i == 6)
	{
		errs += compare_outs(orig(""), mine(""));
		errs += compare_outs(orig("123"), mine("123"));
		errs += compare_outs(orig("asd"), mine("asd"));
		errs += compare_outs(orig("21-asd"), mine("21-asd"));
		errs += compare_outs(orig("+123"), mine("+123"));
		errs += compare_outs(orig("-123"), mine("-123"));
		errs += compare_outs(orig("+-123"), mine("+-123"));
		errs += compare_outs(orig("+-123"), mine("+-123"));
		errs += compare_outs(orig("-0"), mine("-0"));
		errs += compare_outs(orig("2147483647"), mine("2147483647"));
		errs += compare_outs(orig("-2147483648"), mine("-2147483648"));
		errs += compare_outs(orig("-2147483649"), mine("-2147483649"));
		errs += compare_outs(orig("2147483649"), mine("2147483649"));
	}
	// strlen
	else if (i == 7)
	{
		errs += compare_outs(orig(mem[0]), mine(mem[0]));
		errs += compare_outs(orig(""), mine(""));
	}
	return (errs);
}

int	main(void)
{
	int	errors;

	char *names[] = {"ft_memchr", "ft_strchr", "ft_strrchr", "ft_memcmp",
		"ft_strncmp", "ft_strnstr", "ft_atoi", "ft_strlen"};
	void (*mine[])() = {ft_memchr, ft_strchr, ft_strrchr, ft_memcmp, ft_strncmp,
		ft_strnstr, ft_atoi, ft_strlen};
	void (*orig[])() = {memchr, strchr, strrchr, memcmp, strncmp, strnstr, atoi,
		strlen};
	for (int i = 0; i < 8; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += run_test(i, orig[i], mine[i]);
		errors += run_test(i, orig[i], mine[i]);
		errors += run_test(i, orig[i], mine[i]);
		errors += run_test(i, orig[i], mine[i]);
		errors += run_test(i, orig[i], mine[i]);
		errors += run_test(i, orig[i], mine[i]);
		printf("Done: %d errors found\n", errors);
	}
}
