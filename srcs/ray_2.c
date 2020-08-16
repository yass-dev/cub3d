/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:02:07 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/12 10:54:28 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "player.h"
#include "map.h"

int		get_wall_side(t_pos pos, t_data *data, t_pos wall_pos)
{
	if (pos.x % data->block_size != 0 && pos.y % data->block_size != 0)
		return (NO);
	if (pos.x % data->block_size == 0 && pos.x == wall_pos.x)
		return (WE);
	else if (pos.x % data->block_size == 0 && pos.x != wall_pos.x)
		return (EA);
	else if (pos.x % data->block_size != 0 && pos.y == wall_pos.y)
		return (SO);
	else
		return (NO);
}

int		is_on_sprite(t_pos pos, t_data *data, int h)
{
	t_map		*map;
	t_player	*player;
	t_sprite	sprite;
	int			i;

	i = 0;
	map = data->map;
	player = data->player;
	while (map->sprites[i].pos.x != -1)
	{
		sprite = map->sprites[i];
		if (pos.x >= sprite.pos.x
			&& pos.x <= sprite.pos.x + data->block_size
			&& pos.y >= sprite.pos.y
			&& pos.y <= sprite.pos.y + data->block_size)
		{
			map->sprites[i].is_visible = 1;
			map->sprites[i].distance = h;
			return (i);
		}
		i++;
	}
	return (-1);
}
