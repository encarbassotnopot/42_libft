/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:11:29 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 19:12:10 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests/tests.h"
int	test_memset(void)
{
	int				errs;
	size_t			allowed_size;
	size_t			max_size;
	unsigned char	og_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	unsigned char	my_mem[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	allowed_size = 63;
	max_size = 20;
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
