/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:26:03 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 11:30:53 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"

int		map_parse_5(t_tmp *t, t_map *map, t_data *data, char *sprite_filename)
{
	if (t->ctmp[t->itmp] == 'N' || t->ctmp[t->itmp] == 'W'
		|| t->ctmp[t->itmp] == 'S' || t->ctmp[t->itmp] == 'E')
	{
		map->player_pos.x = t->itmp * data->block_size;
		map->player_pos.y = t->itmp_2 * data->block_size;
		if (t->ctmp[t->itmp] == 'N')
			map->player_angle = -62;
		else if (t->ctmp[t->itmp] == 'E')
			map->player_angle = 22;
		else if (t->ctmp[t->itmp] == 'S')
			map->player_angle = 108;
		else if (t->ctmp[t->itmp] == 'W')
			map->player_angle = 180;
	}
	else if (t->ctmp[t->itmp] == '2')
	{
		init_sprite(&map->sprites[t->itmp_4], sprite_filename, data);
		map->sprites[t->itmp_4].pos.x = t->itmp * data->block_size;
		map->sprites[t->itmp_4++].pos.y = t->itmp_2 * data->block_size;
	}
	return (1);
}

int		map_parse_6(t_map *map, t_data *d, t_tmp t)
{
	t_tmp	tm;
	char	*s;

	s = map->str;
	tm.ctmp = ft_substr(s, 0, d->map_size.x);
	tm.ctmp_2 = ft_substr(s, ft_strlen(s) - d->map_size.x, d->map_size.x);
	if (!contains_only_char(tm.ctmp, '1')
		|| !contains_only_char(tm.ctmp_2, '1'))
		ft_exit(d, "Error\nmap must be surrounded of walls !");
	free(tm.ctmp);
	free(tm.ctmp_2);
	map->walls[t.itmp_3].pos.x = -1;
	map->sprites[t.itmp_4].pos.x = -1;
	return (1);
}

t_map	*create_map(int fd, char *filename, t_data *data)
{
	t_map	*map;
	t_tmp	t;
	char	*s;

	map = sub_init_map(&t, data, filename);
	while (get_next_line(fd, &t.ctmp))
	{
		t.itmp = 0;
		if (map_parse(&s, &t, data))
			t.itmp = 0;
		else if (map_parse_2(&t, data))
			t.itmp = 0;
		else if (map_parse_3(&t, map, data))
		{
			while (t.ctmp[t.itmp] != '\0' && map_parse_4(&t, map, data)
					&& map_parse_5(&t, map, data, s))
				t.itmp++;
			t.itmp_2++;
		}
		free(t.ctmp);
	}
	if (map_parse_6(map, data, t) && ft_free(t.ctmp) && ft_free(s))
		return (map);
	return (map);
}

void	load_wall_texture(t_data *data, char *line, int code)
{
	t_image	i;
	char	*tmp;
	char	*tmp_2;

	tmp = cut_str(line, gncp(line, 2), ft_strlen(line));
	tmp_2 = ft_strjoin("Error\nTexture not found : ", tmp);
	if (open(tmp, O_RDONLY) < 0)
		ft_exit(data, tmp_2);
	free(tmp_2);
	i.image = mlx_xpm_file_to_image(data->mlx_ptr, tmp, &i.width, &i.height);
	free(tmp);
	if (i.image == NULL)
		ft_exit(data, "MLX ERROR");
	i.addr = mlx_get_data_addr(i.image, &i.bpp, &i.size_line, &i.endian);
	data->textures[code] = i;
}

int		get_wall_number(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		wall_nb;

	fd = open(filename, O_RDONLY);
	wall_nb = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '1')
				wall_nb++;
			i++;
		}
		free(line);
	}
	free(line);
	close(fd);
	return (wall_nb);
}
