/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:15:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/19 18:03:27 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_T
# include <stddef.h>
# include <stdint.h>

unsigned int	test_bzero(void);
unsigned int	test_memcpy(void);
unsigned int	test_memmove(void);
unsigned int	test_memchr(void);
unsigned int	test_strchr(void);
unsigned int	test_strrchr(void);
unsigned int	test_memcmp(void);
unsigned int	test_strncmp(void);
unsigned int	test_strnstr(void);
unsigned int	test_atoi(void);
unsigned int	test_strlen(void);
unsigned int	test_memmove(void);
unsigned int	test_memset(void);
unsigned int	test_strdup(void);
unsigned int	test_strl_x(void);
unsigned int	test_substr(void);
unsigned int	test_strjoin(void);
unsigned int	test_strtrim(void);
unsigned int	test_split(void);
unsigned int	test_char_isx(void);
unsigned int	test_strlx(void);
unsigned int	test_itoa(void);
unsigned int	test_strmapi(void);
unsigned int	test_striteri(void);
unsigned int	test_putx_fd(void);
unsigned int	test_one_str(const char *my_mem, const char *og_mem);
void			print_mem(const char *start, size_t len);
int				test_mem(unsigned char *my_mem, unsigned char *og_mem,
					unsigned char *my_dst, unsigned char *og_dst,
					size_t mem_size);
int				test_one_mem(unsigned char *my_mem, unsigned char *og_mem,
					size_t mem_size);
unsigned int	compare_outs(intptr_t orig, intptr_t mine);
unsigned int	test_str_list(const char **my_list, const char **ex_list);
#endif
