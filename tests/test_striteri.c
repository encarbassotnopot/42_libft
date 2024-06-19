/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:47:24 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 17:15:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	upper_lower(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

unsigned int	test_striteri(void)
{
	unsigned int	errs;
	char			*my_in;
	char			*str[] = {"", "a", "ASCV", "123", "aSD\0a"};
	char			*expected[] = {"", "A", "AsCv", "123", "AsD"};

	errs = 0;
	for (int i = 0; i < 5; i++)
	{
		my_in = strdup(str[i]);
		printf("Testing ft_striteri(\"%s\", upper_lower)\n", str[i]);
		ft_striteri(my_in, upper_lower);
		errs += test_one_str(my_in, expected[i]);
		printf("Freeing values.\n");
		free(my_in);
	}
	return (errs);
}
