/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:30:17 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/15 18:15:50 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <string.h>

unsigned int	test_memcpy(void)
{
	unsigned int	errs;
	size_t			allowed_size;

	unsigned char og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char og_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	unsigned char my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char my_dst[] = "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	errs = 0;
	allowed_size = 63;
	memcpy(og_dst, og_mem, allowed_size);
	ft_memcpy(my_dst, my_mem, allowed_size);
	errs += test_mem(my_mem, og_mem, my_dst, og_dst, allowed_size);
	return (errs);
}
