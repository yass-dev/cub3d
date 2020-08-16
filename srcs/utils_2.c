/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:37:12 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 12:08:16 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map.h"
#include "player.h"

int			count_sprites(char *str)
{
	int		i;
	int		count;
	int		fd;
	char	*line;

	i = 0;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (contains_only_wall_char(line))
		{
			i = 0;
			while (line[i] != '\0')
				if (line[i++] == '2')
					count++;
		}
		free(line);
	}
	free(line);
	return (count);
}

void		clear_image(t_data *data)
{
	clear_img(data);
}

void		ft_exit(t_data *data, char *str)
{
	t_player	*player;
	t_map		*map;
	int			i;

	i = 0;
	player = data->player;
	map = data->map;
	ft_printf("%s\n", str);
	if (map)
	{
		free(map->walls);
		free(map->sprites);
		free(map->str);
		free(map);
	}
	exit(0);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1 || !*s2)
			break ;
		s1++;
		s2++;
	}
	return (0);
}

int			contains_only_char(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
