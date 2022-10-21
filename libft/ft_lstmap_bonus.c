/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:23:38 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:58:36 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == NULL)
		return (0);
	head = ft_lstnew((*f)(lst->content));
	if (head == NULL)
		return (NULL);
	tmp = head;
	while (lst->next)
	{
		tmp->next = ft_lstnew((*f)(lst->next->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&head, (*del));
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
