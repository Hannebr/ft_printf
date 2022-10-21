/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 10:23:47 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 21:06:28 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == NULL)
		return (0);
	size = 1;
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
