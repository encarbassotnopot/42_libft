/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putx_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:45:18 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:00 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	test_putx_fd(void)
{
	int		i;
	int		fd;
	char	*filename;
	char	*putchar_line;
	int		ints[] = {0, 1, -1, 23423, -293746, INT_MIN, INT_MAX};

	filename = "./tests/last_output.txt";
	putchar_line = "Testing putchar.";
	printf("Testing all ft_putx_fd funcs.\n"
			"WARNING: No automated testing, "
			"diff the last_output.txt to the expected_output.txt file to check for errors.\n");
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
	{
		printf("ERROR: Couldnt't write to file %s\n", filename);
		return (1000);
	}
	for (i = 0; putchar_line[i]; i++)
		ft_putchar_fd(putchar_line[i], fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Testing putstr.", fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("Testing putendl.", fd);
	ft_putstr_fd("Testing putnbr: ", fd);
	for (i = 0; i < 6; i++)
	{
		ft_putnbr_fd(ints[i], fd);
		ft_putstr_fd(", ", fd);
	}
	ft_putnbr_fd(ints[i], fd);
	ft_putendl_fd("", fd);
	close(fd);
	return (0);
}
