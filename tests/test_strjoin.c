/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:12:40 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/18 12:37:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	test_strjoin(void)
{
	unsigned int	errs;
	char			*my_out;
	char			*str1[] = {"", "a", "ascv", "abc", "123", "asd\0a"};
	char			*str2[] = {"", "123", "", "abc", "45\0asd", "asd\0a"};
	char			*expected[] = {"", "a123", "ascv", "abcabc", "12345", "asdasd"};


	errs = 0;
	for (int i = 0; i < 5; i++)
	{
		printf("Testing ft_strjoin(\"%s\", \"%s\")\n", str1[i], str2[i]);
		my_out = ft_strjoin(str1[i], str2[i]);
		errs += test_one_str(my_out, expected[i]);
		printf("Freeing values.\n");
		free(my_out);
	}
	return (errs);
}
