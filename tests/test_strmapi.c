/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:47:24 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:13 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	upper_lower(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

unsigned int	test_strmapi(void)
{
	unsigned int	errs;
	char			*my_out;
	char			*str[] = {"", "a", "ASCV", "123", "aSD\0a"};
	char			*expected[] = {"", "A", "AsCv", "123", "AsD"};


	errs = 0;
	for (int i = 0; i < 5; i++)
	{
		printf("Testing ft_strmapi(\"%s\", upper_lower)\n", str[i]);
		my_out = ft_strmapi(str[i], upper_lower);
		errs += test_one_str(my_out, expected[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
