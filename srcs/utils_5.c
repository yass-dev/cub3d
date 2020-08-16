/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:13:35 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/12 10:57:06 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_next_line.h"

int		is_white_space(char c)
{
	if (c == ' ' || c == '\0' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		only_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_white_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_map_name(t_data *data, char *str)
{
	int	l;

	l = ft_strlen(str);
	if (!(str[l - 4] == '.' && str[l - 3] == 'c' && str[l - 2] == 'u'
		&& str[l - 1] == 'b') || open(str, O_RDONLY) < 0)
		ft_exit(data, "Error\nIn map name");
}

void	init_key_map(t_data *data)
{
	data->r = 0;
	data->no = 0;
	data->ea = 0;
	data->we = 0;
	data->so = 0;
	data->s = 0;
	data->c = 0;
	data->f = 0;
}

void	check_double(t_data *data, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (line[0] == 'N' && line[1] == 'O' && data->no == 1)
			ft_exit(data, "Error\nRedefinition of NO");
		else if (line[0] == 'N' && line[1] == 'O' && data->no == 0)
			data->no = 1;
		else if (line[0] == 'E' && line[1] == 'A' && data->ea == 1)
			ft_exit(data, "Error\nRedefinition of EA");
		else if (line[0] == 'E' && line[1] == 'A' && data->ea == 0)
			data->ea = 1;
		else if (line[0] == 'W' && line[1] == 'E' && data->we == 1)
			ft_exit(data, "Error\nRedefinition of WE");
		else if (line[0] == 'W' && line[1] == 'E' && data->we == 0)
			data->we = 1;
		else if (line[0] == 'S' && line[1] == 'O' && data->so == 1)
			ft_exit(data, "Error\nRedefinition of SO");
		else if (line[0] == 'S' && line[1] == 'O' && data->so == 0)
			data->so = 1;
		check_double_2(data, line);
		free(line);
	}
	free(line);
}
