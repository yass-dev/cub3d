/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:15:59 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/08 17:12:51 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	src_size = 0;
	dest_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size > 0)
	{
		n = (src_size >= size ? size - 1 : src_size);
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[n] = '\0';
	}
	return (src_size);
}
