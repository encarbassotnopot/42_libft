/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:46:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 15:48:34 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_strchr_idx(const char *s, int c)
{
	unsigned char	*my_str;
	unsigned char	my_chr;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	my_str = (unsigned char *)s;
	my_chr = (unsigned char)c;
	while (my_str[count] != my_chr)
	{
		if (my_str[count] == '\0')
			return (-1);
		count++;
	}
	return (count);
}
