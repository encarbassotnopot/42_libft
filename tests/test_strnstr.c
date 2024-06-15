/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:57:56 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 17:34:45 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <bsd/string.h>
#include <stdint.h>

unsigned int	test_strnstr(void)
{
	unsigned int	errs;
	char			*mem;

	mem = "ABCDEFGHIJKLMNOPQABCDEABDE";
	errs = 0;
	errs += compare_outs((intptr_t)strnstr(mem, "", 5),
			(intptr_t)ft_strnstr(mem, "", 5));
	errs += compare_outs((intptr_t)strnstr(mem, "DEF", 4),
			(intptr_t)ft_strnstr(mem, "DEF", 4));
	errs += compare_outs((intptr_t)strnstr(mem, "DEF", 5),
			(intptr_t)ft_strnstr(mem, "DEF", 5));
	errs += compare_outs((intptr_t)strnstr(mem, "DEF", 6),
			(intptr_t)ft_strnstr(mem, "DEF", 6));
	errs += compare_outs((intptr_t)strnstr(mem, "DEf", 10),
			(intptr_t)ft_strnstr(mem, "DEf", 10));
	errs += compare_outs((intptr_t)strnstr(mem, "123", 100),
			(intptr_t)ft_strnstr(mem, "123", 100));
	errs += compare_outs((intptr_t)strnstr("123", mem, 100),
			(intptr_t)ft_strnstr("123", mem, 100));
	errs += compare_outs((intptr_t)strnstr("", mem, 100),
			(intptr_t)ft_strnstr("", mem, 100));
	errs += compare_outs((intptr_t)strnstr(mem, mem, 100),
			(intptr_t)ft_strnstr(mem, mem, 100));
	errs += compare_outs((intptr_t)strnstr("", "", 100),
			(intptr_t)ft_strnstr("", "", 100));
	return (errs);
}
