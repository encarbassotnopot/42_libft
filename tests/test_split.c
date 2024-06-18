/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:54:53 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/18 16:01:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_split(void)
{
	unsigned int	errs;
	char			**my_out;

	char strs[] = {"",
					"  ",
					"fskd sd f daf sd fsdfs",
					"    fskd sd f daf sd fsdfs",
					"fskd sd f daf sd fsdfs"
					"    fskd sd f daf sd fsdfs   "};
	char **expected[] = {{NULL},
						{NULL},
						{"fskd","sd", "f", "df", "sd", "fsdfs", NULL},
						{"fskd","sd", "f", "df", "sd", "fsdfs", NULL},
						{"fskd","sd", "f", "df", "sd", "fsdfs", NULL},
						{"fskd","sd", "f", "df", "sd", "fsdfs", NULL};
	errs = 0;
	for (int i = 0; i < 6; i++)
	{
		printf("Testing ft_split(\"%s\")\n", strs[i]);
		my_out = ft_strtrim(strs[i]);
		errs += test_str_dict(my_out, expected[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
