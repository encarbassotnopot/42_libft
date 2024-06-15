/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:08:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:14:38 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "tests.h"
#include <stdlib.h>
#include <string.h>

unsigned int	test_memcmp(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void *) * 3);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[0], 10),
			(intptr_t)ft_memcmp(mem[0], mem[0], 10));
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[1], 10),
			(intptr_t)ft_memcmp(mem[0], mem[1], 10));
	errs += compare_outs((intptr_t)memcmp(mem[0], mem[1], 27),
			(intptr_t)ft_memcmp(mem[0], mem[1], 27));
	errs += compare_outs((intptr_t)memcmp(mem[1], mem[2], 27),
			(intptr_t)ft_memcmp(mem[1], mem[2], 27));
	errs += compare_outs((intptr_t)memcmp(mem[1], mem[2], 10),
			(intptr_t)ft_memcmp(mem[1], mem[2], 10));
	free(mem);
	return (errs);
}
