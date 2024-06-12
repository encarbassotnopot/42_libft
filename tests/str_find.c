/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/12 16:07:31 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	compare_outs(intptr_t orig, intptr_t mine)
{
	if (orig != mine)
	{
		printf("ERROR! Return value mismatched: og returns %d, mine returns %d\n", orig, mine);
		return (1);
	}
	return (0);
}

// tests a custom implementation of a function against the original one
// returns count of mismatched returns
unsigned int	test_memchr(void)
{
	unsigned int	errs;
	size_t			og_out;
	size_t			my_out;
	char			**mem;

	mem = malloc(sizeof(void) * 4);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	mem[3] = "ABCDEFGHIJK\0MNOPQRSTUVWXYZ";
	errs = 0;
	errs += compare_outs((intptr_t)memchr(mem[0], 'B', 27), (intptr_t)ft_memchr(mem[0],
			'B', 27));
	errs += compare_outs((intptr_t)memchr(mem[0], 'b', 27), (intptr_t)ft_memchr(mem[0],
			'b', 27));
	errs += compare_outs((intptr_t)memchr(mem[2], 'Q', 10), (intptr_t)ft_memchr(mem[2],
			'Q', 10));
	errs += compare_outs((intptr_t)memchr(mem[2], 'Q', 27), (intptr_t)ft_memchr(mem[2],
			'Q', 27));
	errs += compare_outs((intptr_t)memchr(mem[2], 'q', 27), (intptr_t)ft_memchr(mem[2],
			'q', 27));
	free(mem);
	return (errs);
}

unsigned int	test_strchr(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void) * 4);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	mem[3] = "ABCDEFGHIJK\0MNOPQRSTUVWXYZ";
	errs = 0;
	errs += compare_outs((intptr_t)strchr(mem[0], 'B'), (intptr_t)ft_strchr(mem[0], 'B'));
	errs += compare_outs((intptr_t)strchr(mem[0], 'b'), (intptr_t)ft_strchr(mem[0], 'b'));
	errs += compare_outs((intptr_t)strchr(mem[2], 'Q'), (intptr_t)ft_strchr(mem[2], 'Q'));
	errs += compare_outs((intptr_t)strchr(mem[2], 'q'), (intptr_t)ft_strchr(mem[2], 'q'));
	free(mem);
	return (errs);
}
unsigned int	test_strrchr(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void) * 3);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)strrchr(mem[0], 'B'), (intptr_t)ft_strrchr(mem[0],
			'B'));
	errs += compare_outs((intptr_t)strrchr(mem[0], 'b'), (intptr_t)ft_strrchr(mem[0],
			'b'));
	errs += compare_outs((intptr_t)strrchr(mem[2], 'Q'), (intptr_t)ft_strrchr(mem[2],
			'Q'));
	errs += compare_outs((intptr_t)strrchr(mem[2], 'q'), (intptr_t)ft_strrchr(mem[2],
			'q'));
	free(mem);
	return (errs);
}
unsigned int	test_memcmp(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void) * 3);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[0], 10), (intptr_t)ft_memcmp(mem[0],
			mem[0], 10));
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[1], 10), (intptr_t)ft_memcmp(mem[0],
			mem[1], 10));
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[1], 27), (intptr_t)ft_memcmp(mem[0],
			mem[1], 27));
	errs += compare_outs((intptr_t)memcmp(mem[1], mem[2], 27), (intptr_t)ft_memcmp(mem[1],
			mem[2], 27));
	errs += compare_outs((intptr_t)memcmp(mem[1], mem[2], 27), (intptr_t)ft_memcmp(mem[1],
			mem[2], 10));
	free(mem);
	return (errs);
}
unsigned int	test_strncmp(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void) * 3);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)strncmp(mem[0], mem[0], 10),
		(intptr_t)ft_strncmp(mem[0], mem[0], 10));
	errs += compare_outs((intptr_t)strncmp(mem[0], mem[1], 10),
		(intptr_t)ft_strncmp(mem[0], mem[1], 10));
	errs += compare_outs((intptr_t)strncmp(mem[0], mem[1], 27),
		(intptr_t)ft_strncmp(mem[0], mem[1], 27));
	errs += compare_outs((intptr_t)strncmp(mem[1], mem[2], 27),
		(intptr_t)ft_strncmp(mem[1], mem[2], 27));
	errs += compare_outs((intptr_t)strncmp(mem[1], mem[2], 27),
		(intptr_t)ft_strncmp(mem[1], mem[2], 10));
	free(mem);
	return (errs);
}

unsigned int	test_strnstr(void)
{
	unsigned int	errs;
	char			*mem;

	mem = "ABCDEFGHIJKLMNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)strnstr(mem, "DEF", 5), (intptr_t)ft_strnstr(mem,
			"DEF", 5));
	errs += compare_outs((intptr_t)strnstr(mem, "DEf", 10), (intptr_t)ft_strnstr(mem,
			"DEf", 10));
	errs += compare_outs((intptr_t)strnstr(mem, "123", 100), (intptr_t)ft_strnstr(mem,
			"123", 100));
	errs += compare_outs((intptr_t)strnstr("123", mem, 100), (intptr_t)ft_strnstr("123",
			mem, 100));
	return (errs);
}
unsigned int	test_atoi(void)
{
	unsigned int	errs;

	errs = 0;
	errs += compare_outs((intptr_t)atoi(""), (intptr_t)ft_atoi(""));
	errs += compare_outs((intptr_t)atoi("123"), (intptr_t)ft_atoi("123"));
	errs += compare_outs((intptr_t)atoi("asd"), (intptr_t)ft_atoi("asd"));
	errs += compare_outs((intptr_t)atoi("21-asd"), (intptr_t)ft_atoi("21-asd"));
	errs += compare_outs((intptr_t)atoi("+123"), (intptr_t)ft_atoi("+123"));
	errs += compare_outs((intptr_t)atoi("-123"), (intptr_t)ft_atoi("-123"));
	errs += compare_outs((intptr_t)atoi("+-123"), (intptr_t)ft_atoi("+-123"));
	errs += compare_outs((intptr_t)atoi("+-123"), (intptr_t)ft_atoi("+-123"));
	errs += compare_outs((intptr_t)atoi("-0"), (intptr_t)ft_atoi("-0"));
	errs += compare_outs((intptr_t)atoi("2147483647"), (intptr_t)ft_atoi("2147483647"));
	errs += compare_outs((intptr_t)atoi("-2147483648"), (intptr_t)ft_atoi("-2147483648"));
	errs += compare_outs((intptr_t)atoi("-2147483649"), (intptr_t)ft_atoi("-2147483649"));
	errs += compare_outs((intptr_t)atoi("2147483649"), (intptr_t)ft_atoi("2147483649"));
	return (errs);
}

unsigned int	test_strlen(void)
{
	unsigned int	errs;
	char			*mem;

	mem = "ABCDEFGHIJKLMNOPQABCDEABDE";
	errs += compare_outs((intptr_t)strlen(mem), (intptr_t)ft_strlen(mem));
	errs += compare_outs((intptr_t)strlen(""), (intptr_t)ft_strlen(""));
	return (errs);
}

int	main(void)
{
	unsigned int	errors;

	char *names[] = {"ft_memchr", "ft_strchr", "ft_strrchr", "ft_memcmp",
		"ft_strncmp", "ft_strnstr", "ft_atoi"};
	unsigned int (*tests[])() = {test_memchr, test_strchr, test_strrchr,
		test_memcmp, test_strncmp, test_strnstr, test_atoi, test_strlen};
	for (int i = 0; i < 8; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += tests[i]();
		printf("Done: %d errors found\n", errors);
	}
}
