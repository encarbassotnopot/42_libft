/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:43:24 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 11:54:13 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	nofree(void *it)
{
	printf("not freeing: %s\n", (char *)it);
}
static void	dofree(void *it)
{
	printf("freeing: %s\n", (char *)it);
	free(it);
}
static void	print_item(void *it)
{
	printf("printing item: %s\n", (char *)it);
}
static void	*str_up(void *it)
{
	char	*ot;
	char	*ut;
	size_t	i;

	ot = (char *)it;
	ut = malloc(ft_strlen(ot) + 1);
	i = 0;
	while (ot[i])
	{
		ut[i] = ft_toupper(ot[i]);
		i++;
	}
	return (ut);
}
int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*lstup;

	lst = ft_lstnew("dos");
	printf("current list size = %d\n", ft_lstsize(lst));
	new = ft_lstnew("un");
	ft_lstadd_front(&lst, new);
	printf("current list size = %d\n", ft_lstsize(lst));
	new = ft_lstnew("tres");
	ft_lstadd_back(&lst, new);
	printf("current list size = %d\n", ft_lstsize(lst));
	printf("this should be one = %d\n", ft_lstsize(ft_lstlast(lst)));
	lstup = ft_lstmap(lst, str_up, dofree);
	ft_lstiter(lstup, print_item);
	ft_lstclear(&lst->next, nofree);
	ft_lstiter(lst, print_item);
	ft_lstclear(&lstup->next, dofree);
	ft_lstdelone(lst, nofree);
	ft_lstdelone(lstup, dofree);

}
