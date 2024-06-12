/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/12 16:45:11 by ecoma-ba         ###   ########.fr       */
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
// tests a custom implementation of a function against the original one
// returns count of mismatched returns
int	test_memset(void)
{
	int		errs;
	size_t	allowed_size;
	size_t	max_size;

	allowed_size = 63;
	max_size = 20;
	unsigned char og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	errs = 0;
	memset(og_mem, 40, allowed_size);
	ft_memset(my_mem, 40, allowed_size);
	if (memcmp(my_mem, og_mem, max_size))
	{
		printf("ERROR!\n");
		errs++;
	}
	printf("og mem: %.63s\n", og_mem);
	printf("my mem: %.63s\n", my_mem);
	return (errs);
}
int	test_bzero(void)
{
	int		errs;
	size_t	allowed_size;

	allowed_size = 60;
	unsigned char og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
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

int	test_mem(void *(orig)(void *, const void *, size_t), void *(mine)(void *,
			const void *, size_t))
{
	int		errs;
	size_t	allowed_size;

	allowed_size = 63;
	unsigned char og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	unsigned char my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	orig(og_dst, og_mem, allowed_size);
	mine(my_dst, my_mem, allowed_size);
	if (memcmp(my_mem, og_mem, allowed_size))
	{
		printf("ERROR! Different mem.\n");
		errs++;
		printf("og mem: ");
		print_mem(og_mem, 63);
		printf("my mem: ");
		print_mem(my_mem, 63);
	}
	if (memcmp(my_dst, og_dst, allowed_size))
	{
		printf("ERROR! Different dst.\n");
		errs++;
		printf("og dst: ");
		print_mem(og_dst, 63);
		printf("my dst: ");
		print_mem(my_dst, 63);
	}
	return (errs);
}

int	test_memcpy(void)
{
	return (test_mem(memcpy, ft_memcpy));
}

int	test_memmove(void)
{
	return (test_mem(memmove, ft_memmove));
}

int	main(void)
{
	int	errors;

	char *names[] = {"ft_memset", "ft_bzero", "ft_memcpy", "ft_memmove"};
	int (*tests[])(void) = {test_memset, test_bzero, test_memcpy, test_memmove};
	for (int i = 0; i < 4; i++)
	{
		errors = 0;
		printf("Now testing function %s\n", names[i]);
		errors += tests[i]();
		printf("Done: %d errors found\n", errors);
	}
}
