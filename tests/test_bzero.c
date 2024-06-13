/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 19:29:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
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
