/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:20:12 by yel-alou          #+#    #+#             */
/*   Updated: 2020/07/15 17:13:01 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_search_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_str(char *str, int s, int e)
{
	int		i;
	char	*new;

	i = s;
	new = malloc(sizeof(char) * (e - s + 2));
	if (new == NULL)
		return (NULL);
	while (str[i] != '\0' && i <= e)
	{
		new[i - s] = str[i];
		i++;
	}
	new[i - s] = '\0';
	return (new);
}
