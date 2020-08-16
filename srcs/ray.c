/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:30:47 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/12 10:52:04 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "player.h"
#include "map.h"

void	init_ray(t_ray *ray, t_pos pos, float angle, t_pos id_len)
{
	ray->pos = pos;
	ray->angle = angle;
	ray->length = id_len.y;
	ray->impact_length = -1;
	ray->id = id_len.x;
	ray->sprites = NULL;
}

void	draw_ray(t_ray *ray, t_data *data)
{
	t_tmp		t;
	t_pos		pos;
	t_player	*player;
	t_map		*map;

	t.ftmp_5 = 0;
	player = data->player;
	map = data->map;
	t.ftmp_3 = cos(dtor(player->angle - player->fov / 2 + ray->angle));
	t.ftmp_4 = sin(dtor(player->angle - player->fov / 2 + ray->angle));
	ray->sprite_id = -1;
	while (++t.ftmp_5 < ray->length)
	{
		ray_calcul(&t, player->pos, ray);
		pos = ray->tmp_pos;
		if (ray_calcul_2(t, pos, data, ray))
			return ;
	}
	ray->impact_length = -1;
}

void	ray_calcul(t_tmp *t, t_pos pos, t_ray *ray)
{
	t->ftmp = t->ftmp_3 * t->ftmp_5;
	t->ftmp_2 = t->ftmp_4 * t->ftmp_5;
	ray->tmp_pos.x = pos.x + t->ftmp;
	ray->tmp_pos.y = pos.y + t->ftmp_2;
	pos = ray->tmp_pos;
}

int		ray_calcul_2(t_tmp t, t_pos pos, t_data *data, t_ray *ray)
{
	t_player	*player;
	t_map		*map;

	player = data->player;
	map = data->map;
	if ((t.itmp = is_on_sprite(pos, data, t.ftmp_5)) != -1)
	{
		ray->sprite_id = t.itmp;
		ray->sprite_dist = t.ftmp_5;
		ray->sprite_impact_pos = pos;
		map->sprites[t.itmp].ray_id = ray->id;
	}
	if ((ray->wall = is_on_wall(pos, data)) != -1)
	{
		ray->impact_pos = pos;
		ray->impact_length = t.ftmp_5;
		ray->wall_side = get_wall_side(pos, data, map->walls[ray->wall].pos);
		return (1);
	}
	return (0);
}

int		is_on_wall(t_pos pos, t_data *data)
{
	t_map	*map;
	int		i;

	map = (t_map*)data->map;
	i = 0;
	while (map->walls[i].pos.x != -1)
	{
		if (pos.x >= map->walls[i].pos.x
			&& pos.x <= map->walls[i].pos.x + data->block_size
			&& pos.y >= map->walls[i].pos.y
			&& pos.y <= map->walls[i].pos.y + data->block_size)
		{
			map->walls[i].ray_nb += 1;
			return (i);
		}
		i++;
	}
	return (-1);
}
