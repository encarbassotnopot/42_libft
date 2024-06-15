/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:07:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:14:20 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "tests.h"
#include <stdlib.h>
#include <string.h>

unsigned int	test_strchr(void)
{
	unsigned int	errs;
	char			**mem;

	mem = malloc(sizeof(void *) * 4);
	mem[0] = "ABCDEFGHIJKLMNOPQABCDEABDE";
	mem[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mem[2] = "ABCDEFGHIJK\0MNOPQABCDEABDE";
	mem[3] = "ABCDEFGHIJK\0MNOPQRSTUVWXYZ";
	errs = 0;
	errs += compare_outs((intptr_t)strchr(mem[0], 'B'),
			(intptr_t)ft_strchr(mem[0], 'B'));
	errs += compare_outs((intptr_t)strchr(mem[0], 'b'),
			(intptr_t)ft_strchr(mem[0], 'b'));
	errs += compare_outs((intptr_t)strchr(mem[2], 'Q'),
			(intptr_t)ft_strchr(mem[2], 'Q'));
	errs += compare_outs((intptr_t)strchr(mem[2], 'q'),
			(intptr_t)ft_strchr(mem[2], 'q'));
	free(mem);
	return (errs);
}
