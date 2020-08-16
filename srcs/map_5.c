/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:25:27 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/13 09:41:38 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"

void	draw_sprite_2(t_data *data, t_sprite sprite, t_vector2f coef, t_pos hx)
{
	int			j;
	int			k;
	t_player	*player;
	int			c;

	j = -1;
	player = data->player;
	while (++j < hx.x)
	{
		k = -1;
		while (++k < hx.x)
		{
			c = get_pxl_color(sprite.image, j * coef.x, k * coef.y);
			if (c != 0x0 && hx.y - hx.x / 2 + j < data->win_size.x
				&& player->height - hx.x / 2 + k < data->win_size.y
				&& hx.y - hx.x / 2 + j >= 0
				&& player->height / 2 + k >= 0)
				p(data, hx.y - hx.x / 2 + j, player->height - hx.x / 2 + k, c);
		}
	}
}

t_pos	int_to_pos(int x, int y)
{
	t_pos	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	draw_sprite(t_data *data)
{
	t_map		*map;
	t_sprite	s;
	t_vector2f	coef;
	t_tmp		t;

	t.itmp = -1;
	map = data->map;
	while (map->sprites[++t.itmp].pos.x != -1)
	{
		s = map->sprites[t.itmp];
		if (s.is_visible)
		{
			t.itmp_4 = s.height / (float)s.distance * data->screen_dist;
			coef.x = (float)s.width / t.itmp_4;
			coef.y = (float)s.height / t.itmp_4;
			t.itmp_2 = t.itmp_4 / 2;
			t.itmp_3 = s.ray_id;
			draw_sprite_2(data, s, coef, int_to_pos(t.itmp_4, t.itmp_3));
		}
	}
}

int		get_dist(t_pos p, t_pos pos)
{
	return (pow(p.x - pos.x, 2) + pow(p.y - pos.y, 2));
}

void	swap_sprite(t_map *map, int i, t_sprite sprite)
{
	map->sprites[i] = map->sprites[i - 1];
	map->sprites[i - 1] = sprite;
}
