/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:30:12 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/15 13:26:07 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s2_size;

	i = 0;
	s2_size = 0;
	while (s1[i] != '\0' && (int)i < (int)n)
		i++;
	j = i;
	while (s2[i - j] != '\0' && (int)i < (int)n - 1)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if ((int)j < (int)n)
		s1[i] = '\0';
	while (s2[s2_size] != '\0')
		s2_size++;
	return (j + s2_size);
}
