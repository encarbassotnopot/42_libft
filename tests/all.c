/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:05:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:22:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	main(void)
{
	unsigned int	errors;
	char			*names[] = {"ft_memchr", "ft_strchr", "ft_strrchr",
					"ft_memcmp", "ft_strncmp", "ft_strnstr", "ft_atoi",
					"ft_strlen", "ft_memset", "ft_bzero", "ft_memcpy",
					"ft_memmove", "ft_strdup"};

	unsigned int (*tests[])() = {test_memchr, test_strchr, test_strrchr,
		test_memcmp, test_strncmp, test_strnstr, test_atoi, test_strlen,
		test_memset, test_bzero, test_memcpy, test_memmove, test_strdup};
	for (int i = 0; i < 13; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += tests[i]();
		printf("Done: %d errors found\n", errors);
	}
}
