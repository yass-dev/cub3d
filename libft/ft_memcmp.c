/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:09:21 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/08 17:13:32 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = -1;
	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (++i < n && *(ptr + i) == *(ptr2 + i))
		;
	if (i == n)
		return (0);
	return (*(ptr + i) - *(ptr2 + i));
}
