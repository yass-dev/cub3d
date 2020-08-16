/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:43:20 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/12 10:56:37 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			get_pxl_color(t_image image, int x, int y)
{
	int	a;

	a = 0x0;
	if (x >= 0 && x < image.width && y >= 0 && y <= image.height)
		a = *(int*)(image.addr + (x + y * image.width) * image.bpp / 8);
	return (a);
}

void		*ft_malloc(t_data *data, int n)
{
	void	*a;

	a = malloc(n);
	ft_lstadd_back(&data->list, ft_lstnew(a));
	return (a);
}

void		mlx_get_screen_size(void *s, int *a, int *b)
{
	void	*tmp;

	tmp = a;
	tmp = s;
	*a = MAX_WIDTH;
	*b = MAX_HEIGHT;
}

int			ft_free(void *s)
{
	free(s);
	return (1);
}

int			free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}
