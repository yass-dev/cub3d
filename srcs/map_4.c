/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:25:36 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/13 09:40:23 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"

int		get_sprite_number(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		sprite_nb;

	fd = open(filename, O_RDONLY);
	sprite_nb = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '2')
				sprite_nb++;
			i++;
		}
	}
	close(fd);
	return (sprite_nb);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	int		k;
	t_pos	pos;
	t_map	*map;

	i = 0;
	map = data->map;
	while (map->walls[i].pos.x != -1)
	{
		pos = map->walls[i].pos;
		pos.x = pos.x / data->block_size * data->minimap_wall_size;
		pos.y = pos.y / data->block_size * data->minimap_wall_size;
		j = -1;
		while (++j < data->minimap_wall_size)
		{
			k = -1;
			while (++k < data->minimap_wall_size)
				put_pxl_img(data, pos.x + j, pos.y + k, 0x4a708b);
		}
		i++;
	}
}

void	draw_wall(t_data *d)
{
	t_pos		ih;
	t_player	*player;
	t_ray		r;
	t_map		*map;

	player = (t_player*)d->player;
	d->screen_dist = (float)(d->win_size.x / 2) / tan(dtor(player->fov / 2));
	map = d->map;
	ih.x = 0;
	while (ih.x < d->win_size.x)
	{
		r = player->rays[ih.x];
		r.impact_length = (float)cos(dtor(r.angle)) * (float)r.impact_length;
		ih.y = d->block_size / (float)r.impact_length * d->screen_dist;
		draw_column_tex(d, ih.x, ih.y, r.wall_side);
		ih.x++;
	}
}

void	draw_column_tex(t_data *data, int x, int height, int dir)
{
	t_player				*player;
	t_tmp					t;
	t_ray					ray;
	unsigned int			color;

	t.itmp_3 = -1;
	if ((player = data->player) && height > data->win_size.y)
		height = data->win_size.y;
	ray = player->rays[x];
	if ((t.itmp = ray.impact_pos.x % data->block_size) == 0)
		t.itmp = ray.impact_pos.y % data->block_size;
	t.ftmp_2 = (float)data->textures[dir].height / height;
	t.ftmp = (float)data->textures[dir].width / data->block_size;
	while (++t.itmp_3 < player->height - height / 2
		&& t.itmp_3 < data->win_size.y)
		put_pxl_img(data, x, t.itmp_3, data->ceiling_color);
	while (t.itmp_3 < player->height + height / 2
			&& t.itmp_3 < data->win_size.y)
	{
		t.ftmp_3 = (t.itmp_3 - player->height + height / 2) * t.ftmp_2;
		color = get_pxl_color(data->textures[dir], t.itmp * t.ftmp, t.ftmp_3);
		put_pxl_img(data, x, t.itmp_3++, color);
	}
	while (t.itmp_3 < data->win_size.y)
		put_pxl_img(data, x, t.itmp_3++, data->ground_color);
}

void	p(t_data *data, int x, int y, int c)
{
	put_pxl_img(data, x, y, c);
}
