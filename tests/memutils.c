/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:37:09 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 19:38:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_mem(const char *start, size_t len)
{
	for (int i = 0; i < len; i++)
		printf("%02x ", start[i]);
	printf("\n");
}

int	test_mem(unsigned char *my_mem, unsigned char *og_mem,
		unsigned char *my_dst, unsigned char *og_dst, size_t mem_size)
{
	int	errs;

	errs = 0;
	if (memcmp(my_mem, og_mem, mem_size))
	{
		printf("ERROR! Different mem.\n");
		errs++;
		printf("og mem: ");
		print_mem(og_mem, mem_size);
		printf("my mem: ");
		print_mem(my_mem, mem_size);
	}
	if (memcmp(my_dst, og_dst, mem_size))
	{
		printf("ERROR! Different dst.\n");
		errs++;
		printf("og dst: ");
		print_mem(og_dst, mem_size);
		printf("my dst: ");
		print_mem(my_dst, mem_size);
	}
	return (errs);
}
