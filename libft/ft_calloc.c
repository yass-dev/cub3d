/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:02:07 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/08 17:10:47 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(size * n);
	if (ptr == NULL)
		return (NULL);
	while (i < n * size)
	{
		((char*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
