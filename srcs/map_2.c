/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:04:31 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 11:49:32 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"
#include "libft.h"

t_map	*sub_init_map(t_tmp *t, t_data *data, char *filename)
{
	t_map		*map;
	t_sprite	*s;
	t_wall		*w;

	map = ft_malloc(data, sizeof(t_map));
	w = ft_malloc(data, sizeof(t_wall) * (get_wall_number(filename) + 1));
	map->walls = w;
	s = ft_malloc(data, sizeof(t_sprite) * (count_sprites(filename) + 1));
	map->sprites = s;
	map->str = ft_strdup("");
	data->map_size.x = -1;
	t->itmp_3 = 0;
	t->itmp_4 = 0;
	t->itmp_2 = 0;
	data->block_size = BLOCK_SIZE;
	return (map);
}

int		map_parse(char **s, t_tmp *t, t_data *data)
{
	if (line_is_null(t->ctmp))
		return (1);
	else if (t->ctmp[0] == 'S' && t->ctmp[1] != 'O')
		*s = cut_str(t->ctmp, gncp(t->ctmp, 1), ft_strlen(t->ctmp));
	else if (t->ctmp[0] == 'R')
	{
		t->cctmp = ft_split(t->ctmp, ' ');
		if (arr_size(t->cctmp) != 3)
			ft_exit(data, "Error\nResolution error");
		data->win_size.x = ft_atoi(t->cctmp[1]);
		data->win_size.y = ft_atoi(t->cctmp[2]);
		free_arr(t->cctmp);
	}
	else if (t->ctmp[0] == 'E' && t->ctmp[1] == 'A')
		load_wall_texture(data, t->ctmp, EA);
	else if (t->ctmp[0] == 'W' && t->ctmp[1] == 'E')
		load_wall_texture(data, t->ctmp, WE);
	else if (t->ctmp[0] == 'S' && t->ctmp[1] == 'O')
		load_wall_texture(data, t->ctmp, SO);
	else if (t->ctmp[0] == 'N' && t->ctmp[1] == 'O')
		load_wall_texture(data, t->ctmp, NO);
	else
		return (0);
	return (1);
}

int		map_parse_2(t_tmp *t, t_data *data)
{
	int	red;
	int	green;
	int	blue;

	if (t->ctmp[0] == 'F' || t->ctmp[0] == 'C')
	{
		t->ctmp_4 = cut_str(t->ctmp, gncp(t->ctmp, 1), ft_strlen(t->ctmp));
		t->cctmp_2 = ft_split(t->ctmp_4, ',');
		red = ft_atoi(t->cctmp_2[0]);
		green = ft_atoi(t->cctmp_2[1]);
		blue = ft_atoi(t->cctmp_2[2]);
		free(t->ctmp_4);
	}
	if (t->ctmp[0] == 'F')
		data->ground_color = 0x010000 * red + 0x000100 * green + blue;
	else if (t->ctmp[0] == 'C')
		data->ceiling_color = 0x010000 * red + 0x000100 * green + blue;
	else
		return (0);
	free_arr(t->cctmp_2);
	return (1);
}

int		map_parse_3(t_tmp *t, t_map *map, t_data *data)
{
	char	*tmp;

	if (contains_only_wall_char(t->ctmp))
	{
		tmp = t->ctmp;
		t->ctmp = remove_white_space(t->ctmp);
		free(tmp);
		t->ctmp_2 = map->str;
		map->str = ft_strjoin(map->str, t->ctmp);
		free(t->ctmp_2);
	}
	else
		ft_exit(data, "Error\nin map !");
	return (1);
}

int		map_parse_4(t_tmp *t, t_map *map, t_data *data)
{
	if (t->ctmp[0] != '1' || t->ctmp[ft_strlen(t->ctmp) - 1] != '1')
		ft_exit(data, "Error\nmap must be surrounded of walls\n");
	if (data->map_size.x == -1)
		data->map_size.x = ft_strlen(t->ctmp);
	if (data->map_size.x != -1 && data->map_size.x != (int)ft_strlen(t->ctmp)
		&& 1 == 4)
		ft_exit(data, "Error\nmap have different line size !\n");
	if (t->ctmp[t->itmp] == '1')
	{
		map->walls[t->itmp_3].pos.x = t->itmp * data->block_size;
		map->walls[t->itmp_3].pos.y = t->itmp_2 * data->block_size;
		map->walls[t->itmp_3].ray_nb = 0;
		t->itmp_3++;
	}
	return (1);
}
