/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:37:31 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 10:36:02 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map.h"
#include "player.h"

int			ft_abs(int a)
{
	return ((a < 0 ? -a : a));
}

static int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*remove_white_space(char *str)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_white_space(str[i]))
			count++;
		i++;
	}
	new = malloc(sizeof(char) * (count + 1));
	i = 0;
	count = -1;
	while (str[i] != '\0')
	{
		if (!is_white_space(str[i]))
			new[++count] = str[i];
		i++;
	}
	new[++count] = '\0';
	return (new);
}

int			contains_only_wall_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_white_space(str[i]) && str[i] != '0'
			&& str[i] != '1' && str[i] != '2'
			&& str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'S' && str[i] != 'W'
			&& str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void		clear_img(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->win_size.y)
	{
		j = -1;
		while (++j < data->win_size.x)
			put_pxl_img(data, j, i, 0xff77f00);
	}
}
