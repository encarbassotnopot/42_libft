/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/21 19:28:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	t_list	*my_lst;

	my_lst = lst;
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	current = head;
	while (my_lst->next)
	{
		current->content = f(my_lst->content);
		current->next = malloc(sizeof(t_list));
		if (!current->next)
		{
			ft_lstclear(&head, del);
			return (head);
		}
		my_lst = my_lst->next;
		current = current->next;
	}
	current->content = f(my_lst->content);
	current->next = NULL;
	return (head);
}
