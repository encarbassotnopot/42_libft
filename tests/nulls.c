/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nulls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:31:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 23:39:49 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Calling all functions passing null values.\n");
	ft_strjoin(0, 0);
	ft_atoi(0);
	ft_bzero(0, 0);
	ft_isalnum(0);
	ft_isalpha(0);
	ft_isascii(0);
	ft_isdigit(0);
	ft_strdup(0);
	ft_isprint(0);
	ft_memchr(0, 0, 0);
	ft_memcmp(0, 0, 0);
	ft_memcpy(0, 0, 0);
	ft_memmove(0, 0, 0);
	ft_memset(0, 0, 0);
	ft_strchr(0, 0);
	ft_strlcat(0, 0, 0);
	ft_strlcpy(0, 0, 0);
	ft_strlen(0);
	ft_strncmp(0, 0, 0);
	ft_strrchr(0, 0);
	ft_strnstr(0, 0, 0);
	ft_tolower(0);
	ft_toupper(0);
	free(ft_itoa(0));
	ft_strmapi(0, 0);
	ft_striteri(0, 0);
	ft_substr(0, 0, 0);
	ft_strtrim(0, 0);
	ft_split(0, 0);
	ft_putchar_fd(0, 0);
	ft_putstr_fd(0, 0);
	ft_putendl_fd(0, 0);
	ft_putnbr_fd(0, 0);
	free(ft_lstnew(0));
	ft_lstadd_front(0, 0);
	ft_lstsize(0);
	ft_lstlast(0);
	ft_lstadd_back(0, 0);
	ft_lstdelone(0, 0);
	ft_lstclear(0, 0);
	ft_lstiter(0, 0);
	ft_lstmap(0, 0, 0);
	printf("If you see this message and you haven't segfaulted (nor have leaked) your code is ok.\n");
}
