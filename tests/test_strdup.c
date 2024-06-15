/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:09:59 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:26:33 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_strdup(void)
{
	unsigned int	errs;
	char			**mem;
	char			*my_out;
	char			*og_out;

	errs = 0;
	mem = malloc(sizeof(void *) * 4);
	mem[0] = "";
	mem[1] = "123";
	mem[2] = "asd\0a";
	mem[3] = "lkhfdskhdfks";
	for (int i = 0; i < 4; i++)
	{
		my_out = ft_strdup(mem[i]);
		og_out = strdup(mem[i]);
		printf("Now testing value: %s\n", mem[i]);
		errs += test_one_mem(my_out, og_out, strlen(mem[i]) + 1);
		printf("Freeing values.\n");
		free(my_out);
		free(og_out);
	}
	free(mem);
	return (errs);
}
