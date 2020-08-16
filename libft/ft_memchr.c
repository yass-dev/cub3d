/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:00 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/12 09:50:53 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	void			*s2;

	i = 0;
	s2 = (void *)s;
	while (i < n)
	{
		if (((char*)s2)[i] == c)
		{
			return (&s2[i]);
		}
		i++;
	}
	return (NULL);
}
