/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:31:17 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:57:12 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *) malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
