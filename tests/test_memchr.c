/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:03:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/22 09:33:46 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "tests.h"
#include <stdlib.h>
#include <string.h>

unsigned int	test_memchr(void)
{
	unsigned int	errs;
	size_t			og_out;
	size_t			my_out;
	char			**mem;

	mem = malloc(sizeof(void *) * 4);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	mem[3] = "ABCDEFGHIJK\0MNOPQRSTUVWXYZ";
	errs = 0;
	errs += compare_outs((intptr_t)memchr(mem[0], 'B', 27),
			(intptr_t)ft_memchr(mem[0], 'B', 27));
	errs += compare_outs((intptr_t)memchr(mem[0], 'b', 27),
			(intptr_t)ft_memchr(mem[0], 'b', 27));
	errs += compare_outs((intptr_t)memchr(mem[2], 'Q', 10),
			(intptr_t)ft_memchr(mem[2], 'Q', 10));
	errs += compare_outs((intptr_t)memchr(mem[2], 'Q', 27),
			(intptr_t)ft_memchr(mem[2], 'Q', 27));
	errs += compare_outs((intptr_t)memchr(mem[2], 'q', 27),
			(intptr_t)ft_memchr(mem[2], 'q', 27));
	errs += compare_outs((intptr_t)memchr(mem[0], '\0', 27),
			(intptr_t)ft_memchr(mem[0], '\0', 27));
	free(mem);
	return (errs);
}

