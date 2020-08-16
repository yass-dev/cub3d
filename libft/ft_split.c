/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:53:56 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/21 14:55:42 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
		count = 1;
	else
		count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	size_t			nbwords;
	char			*ptr;
	char			**splitted;

	if (!s)
		return (0);
	nbwords = ft_count((char *)s, c);
	if (!(splitted = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (0);
	ptr = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (ptr != s)
				*(splitted++) = ft_substr(ptr, 0, s - ptr);
			ptr = (char *)s + 1;
		}
		s++;
	}
	if (ptr != s)
		*(splitted++) = ft_substr(ptr, 0, s - ptr);
	*splitted = 0;
	return (splitted - nbwords);
}
