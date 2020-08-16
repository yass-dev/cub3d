/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:04:01 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/18 14:13:04 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	ptr = new_list;
	while (lst != NULL)
	{
		if (lst->next)
		{
			new_list->next = ft_lstnew(f(lst->next->content));
			new_list = new_list->next;
		}
		lst = lst->next;
	}
	new_list->next = NULL;
	return (ptr);
	(void)(del(0));
}
