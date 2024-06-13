/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 18:39:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

// tests a custom implementation of a function against the original one
// returns count of mismatched returns

int	test_bzero(void)
{
	int				errs;
	size_t			allowed_size;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	allowed_size = 60;
	bzero(og_mem, allowed_size);
	ft_bzero(my_mem, allowed_size);
	if (memcmp(my_mem, og_mem, allowed_size))
	{
		printf("ERROR!\n");
		errs++;
	}
	printf("og mem: ");
	print_mem(og_mem, 63);
	printf("my mem: ");
	print_mem(my_mem, 63);
	return (errs);
}

int	test_memcpy(void)
{
	int				errs;
	size_t			allowed_size;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

	errs = 0;
	allowed_size = 63;
	memcpy(og_dst, og_mem, allowed_size);
	ft_memcpy(my_dst, my_mem, allowed_size);
	errs += test_mem(my_mem, og_mem, my_dst, og_dst, allowed_size);
	return (errs);
}

int	test_memmove(void)
{
	int				errs;
	size_t			allowed_size;
	size_t			mem_size;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

	errs = 0;
	allowed_size = 30;
	mem_size = 63;
	memmove(&og_mem[15], &og_mem[0], allowed_size);
	ft_memmove(&my_mem[15], &my_mem[0], allowed_size);
	memmove(&og_dst[0], &og_dst[15], allowed_size);
	ft_memmove(&my_dst[0], &my_dst[15], allowed_size);
	errs += test_mem(my_mem, og_mem, my_dst, og_dst, mem_size);
	return (errs);
}

int	main(void)
{
	int		errors;
	char	*names[] = {"ft_memset", "ft_bzero", "ft_memcpy", "ft_memmove"};

	int (*tests[])(void) = {test_memset, test_bzero, test_memcpy, test_memmove};
	for (int i = 0; i < 4; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += tests[i]();
		printf("Done: %d errors found\n", errors);
	}
}
