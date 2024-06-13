/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:10:13 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 19:10:50 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
