/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/14 13:56:20 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

unsigned int	test_bzero(void)
{
	unsigned int		errs;
	size_t	allowed_size;

	unsigned char og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
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
