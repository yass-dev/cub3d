/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:01:04 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/08 17:19:58 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	i = -1;
	if (dest == NULL && src == NULL)
		return (dest);
	if (tmp2 < tmp)
	{
		while ((int)(--n) >= 0)
		{
			tmp[(int)n] = tmp2[(int)n];
		}
	}
	else
	{
		while (++i < (int)n)
		{
			*(tmp + i) = *(tmp2 + i);
		}
	}
	return (dest);
}
