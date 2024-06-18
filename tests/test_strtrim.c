/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:12:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/18 13:16:41 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_strtrim(void)
{
	unsigned int	errs;
	char			*my_out;
	char			*str1[] = {"", "sdfkjhsdk", "asbncv", "xascvcbaaac",
					"0910232jhsgdfjsdgfj324832", "0910232324832"};
	char			*sets[] = {"sdfgd", "", "abc", "abc", "0123456789", "0123456789"};
	char			*expected[] = {"", "sdfkjhsdk", "sbncv", "xascv", "jhsgdfjsdgfj", ""};

	errs = 0;
	for (int i = 0; i < 6; i++)
	{
		printf("Testing ft_strtrim(\"%s\", \"%s\")\n", str1[i], sets[i]);
		my_out = ft_strtrim(str1[i], sets[i]);
		errs += test_one_str(my_out, expected[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
