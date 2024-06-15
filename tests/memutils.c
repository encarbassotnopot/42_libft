/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:37:09 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 17:54:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void	print_mem(const char *start, size_t len)
{
	for (int i = 0; i < len; i++)
		printf("%02x ", start[i]);
	printf("\n");
}

unsigned int	test_one_mem(unsigned char *my_mem, unsigned char *og_mem,
		size_t mem_size)
{
	if (memcmp(my_mem, og_mem, mem_size))
	{
		printf("ERROR! Different mem.\n");
		printf("og mem: ");
		print_mem(og_mem, mem_size);
		printf("my mem: ");
		print_mem(my_mem, mem_size);
		return (1);
	}
	return (0);
}

unsigned int	test_mem(unsigned char *my_mem, unsigned char *og_mem,
		unsigned char *my_dst, unsigned char *og_dst, size_t mem_size)
{
	unsigned int	errs;

	errs = 0;
	printf("Comparing source:\n");
	errs += test_one_mem(my_mem, og_mem, mem_size);
	printf("Comparing destination:\n");
	errs += test_one_mem(my_dst, og_dst, mem_size);
	return (errs);
}

unsigned int	compare_outs(intptr_t orig, intptr_t mine)
{
	if (orig != mine)
	{
		printf("ERROR! Return value mismatched: og returns %d, mine returns "
				"%d\n",
				orig,
				mine);
		return (1);
	}
	return (0);
}
