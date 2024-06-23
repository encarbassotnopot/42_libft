/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:54:53 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 13:51:06 by ecoma-ba         ###   ########.fr       */
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
	char			*strs[] = {"", "  ", "fskd aasda f daf sd fsdfs",
					"    fskd aasda f daf sd fsdfs", "fskd aasda f daf sd fsdfs",
					"    fskd aasda f daf sd fsdfs   "};
	const char		*expected[][10] = {{NULL}, {NULL}, {"fskd", "aasda", "f", "daf",
				"sd", "fsdfs", NULL}, {"fskd", "aasda", "f", "daf", "sd", "fsdfs",
				NULL}, {"fskd", "aasda", "f", "daf", "sd", "fsdfs", NULL}, {"fskd",
				"aasda", "f", "daf", "sd", "fsdfs", NULL}};

	errs = 0;
	for (int i = 0; i < 6; i++)
	{
		printf("Testing ft_split(\"%s\", ' ')\n", strs[i]);
		my_out = ft_split(strs[i], ' ');
		errs += test_str_list((const char **)my_out, expected[i]);
		printf("Freeing values.\n");
		for (int a = 0; my_out[a]; a++)
			free(my_out[a]);
		free(my_out);
	}
	return (errs);
}
