/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/12/28 12:40:03 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;
	unsigned char	*my_s1;
	unsigned char	*my_s2;

	if (!s1 || !s2)
		return (0);
	my_s1 = (unsigned char *)s1;
	my_s2 = (unsigned char *)s2;
	index = 0;
	while ((my_s1[index] != '\0' || my_s2[index] != '\0'))
	{
		if (my_s1[index] != my_s2[index])
		{
			return (my_s1[index] - my_s2[index]);
		}
		index++;
	}
	return (my_s1[index] - my_s2[index]);
}
