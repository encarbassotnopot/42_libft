/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:12:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 00:22:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_substr(void)
{
	unsigned int	errs;
	char			*my_out;
	char			*str[] = {"", "a", "123", "abc", "4567", "asd\0a",
					"lkhfdskhdfks", "abcdefghij"};
	int				start[] = {0, 0, 1, 10, 2, 1, 5, 3};
	size_t			len[] = {0, 1, 5, 10, 2, 80, 5, 4};
	char			*expected[] = {"", "a", "23", "", "67", "sd", "skhdf", "defg"};

	errs = 0;
	for (int i = 0; i < sizeof(str)/sizeof(*str); i++)
	{
		printf("Testing ft_substr(\"%s\", %i, %li)\n", str[i], start[i],
			len[i]);
		my_out = ft_substr(str[i], start[i], len[i]);
		errs += test_one_str(my_out, expected[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
