/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:05:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 10:56:48 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	main(void)
{
	unsigned int	len;
	unsigned int	errors;
	char			*names[] = {"ft_memchr", "ft_strchr", "ft_strrchr",
					"ft_memcmp", "ft_strncmp", "ft_strnstr", "ft_atoi",
					"ft_strlen", "ft_memset", "ft_bzero", "ft_memcpy",
					"ft_memmove", "ft_strdup", "ft_substr", "ft_strjoin",
					"ft_strtrim", "ft_split", "ft_itoa", "ft_strmapi",
					"ft_striteri", "ft_putx_fd"};
	unsigned int	total_errors;

	unsigned int (*tests[])() = {test_memchr, test_strchr, test_strrchr,
		test_memcmp, test_strncmp, test_strnstr, test_atoi, test_strlen,
		test_memset, test_bzero, test_memcpy, test_memmove, test_strdup,
		test_substr, test_strjoin, test_strtrim, test_split, test_itoa,
		test_strmapi, test_striteri, test_putx_fd};
	total_errors = 0;
	total_errors += test_char_isx();
	total_errors += test_strlx();
	for (unsigned int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		printf("Now testing function %s\n", names[i]);
		errors = tests[i]();
		total_errors += errors;
		printf("Done: %d errors found\n", errors);
	}
	printf("All tests finished. %d errors found\n", total_errors);
}
