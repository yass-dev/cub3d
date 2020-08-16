/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:19:53 by yel-alou          #+#    #+#             */
/*   Updated: 2020/06/16 09:04:09 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	if (*alst != NULL)
	{
		list = *alst;
		while (list->next != NULL)
		{
			list = list->next;
		}
		list->next = new;
	}
	else
	{
		new->next = NULL;
		*alst = new;
	}
}
