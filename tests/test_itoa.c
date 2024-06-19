/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:45:03 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 16:26:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	test_itoa(void)
{
	unsigned int	errs;
	char			*my_out;
	int				ints[] = {0, 1, -1, 23423, -293746, INT_MIN, INT_MAX};
	char			*outs[] = {"0", "1", "-1", "23423", "-293746",
					"-2147483648", "2147483647"};

	errs = 0;
	for (int i = 0; i < 7; i++)
	{
		printf("Testing ft_itoa(%d)\n", ints[i]);
		my_out = ft_itoa(ints[i]);
		errs += test_one_str(my_out, outs[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
