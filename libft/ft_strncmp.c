/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:31:58 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/15 13:25:06 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	s1_size;
	unsigned int	s2_size;

	i = 0;
	s1_size = 0;
	s2_size = 0;
	if (!n)
		return (0);
	while (s1[s1_size] != '\0')
		s1_size++;
	while (s2[s2_size] != '\0')
		s2_size++;
	if (s1_size != s2_size && s1_size < n)
		return ((s1_size > s2_size) ? 1 : -1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] < (unsigned char)s2[i]) ? -1 : 1);
		i++;
	}
	return (0);
}
