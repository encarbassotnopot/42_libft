/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:07:55 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:14:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"
#include "libft.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

unsigned int	test_strrchr(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void *) * 3);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)strrchr(mem[0], 'B'),
		(intptr_t)ft_strrchr(mem[0], 'B'));
	errs += compare_outs((intptr_t)strrchr(mem[0], 'b'),
		(intptr_t)ft_strrchr(mem[0], 'b'));
	errs += compare_outs((intptr_t)strrchr(mem[2], 'Q'),
		(intptr_t)ft_strrchr(mem[2], 'Q'));
	errs += compare_outs((intptr_t)strrchr(mem[2], 'q'),
		(intptr_t)ft_strrchr(mem[2], 'q'));
	free(mem);
	return (errs);
}
