/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:09:43 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:13:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int	test_atoi(void)
{
	unsigned int	errs;
	char			**mem;

	errs = 0;
	mem = malloc(sizeof(void *) * 13);
	mem[0] = "";
	mem[1] = "123";
	mem[2] = "asd";
	mem[3] = "21-asd";
	mem[4] = "+123";
	mem[5] = "-123";
	mem[6] = "+-123";
	mem[7] = "+-123";
	mem[8] = "-0";
	mem[9] = "2147483647";
	mem[10] = "-2147483648";
	mem[11] = "-2147483649";
	mem[12] = "2147483649";
	for (int i = 0; i < 13; i++)
	{
		printf("Now testing value: %s\n", mem[i]);
		errs += compare_outs((intptr_t)atoi(mem[i]), (intptr_t)ft_atoi(mem[i]));
	}
	free(mem);
	return (errs);
}
