/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:23 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 10:44:24 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

void	check_double_2(t_data *data, char *line)
{
	if (line[0] == 'S' && line[1] != 'O' && data->s == 1)
		ft_exit(data, "Error\nRedefinition of S");
	else if (line[0] == 'S' && line[1] != 'O' && data->s == 0)
		data->s = 1;
	else if (line[0] == 'C' && data->c == 1)
		ft_exit(data, "Error\nRedefinition of C");
	else if (line[0] == 'C' && data->c == 0)
		data->c = 1;
	else if (line[0] == 'F' && data->f == 1)
		ft_exit(data, "Error\nRedefinition of F");
	else if (line[0] == 'F' && data->f == 0)
		data->f = 1;
	else if (line[0] == 'R' && data->r == 1)
		ft_exit(data, "Error\nRedefinition of R");
	else if (line[0] == 'R' && data->r == 0)
		data->r = 1;
}

int		gncp(char *str, int pos)
{
	while (str[++pos] != '\0')
		if (ft_isalnum(str[pos]))
			return (pos);
	return (-1);
}

int		arr_size(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		sis(t_data *data, t_pos src)
{
	data->img_size.x = src.x;
	data->img_size = data->win_size;
	return (1);
}

int		line_is_null(char *str)
{
	int	i;

	if (ft_strlen(str) == 0)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}
