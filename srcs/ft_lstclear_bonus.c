/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:28:08 by yel-alou          #+#    #+#             */
/*   Updated: 2020/06/16 09:04:34 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	if (*lst == NULL)
		return ;
	while (list != NULL)
	{
		tmp = list->next;
		del(list->content);
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
