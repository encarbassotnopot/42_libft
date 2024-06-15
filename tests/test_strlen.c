/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:09:59 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:16:20 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_strlen(void)
{
	unsigned int	errs;
	char			**mem;

	errs = 0;
	mem = malloc(sizeof(void *) * 4);
	mem[0] = "";
	mem[1] = "123";
	mem[2] = "asd\0a";
	mem[3] = "lkhfdskhdfks";
	for (int i = 0; i < 4; i++)
	{
		printf("Now testing value: %s\n", mem[i]);
		errs += compare_outs((intptr_t)strlen(mem[i]),
			(intptr_t)ft_strlen(mem[i]));
	}
	free(mem);
	return (errs);
}
