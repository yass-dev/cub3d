/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:22:58 by yel-alou          #+#    #+#             */
/*   Updated: 2020/07/22 10:39:12 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"

void	sort_sprites(t_data *data, t_sprite sprite, t_tmp t)
{
	t_map		*map;
	t_pos		player_dist;
	t_player	*player;
	t_pos		pos;

	map = data->map;
	player = data->player;
	t.itmp_2 = 1;
	pos = player->pos;
	while (t.itmp_2)
	{
		t.itmp = -1;
		t.itmp_2 = 0;
		while (map->sprites[++t.itmp].pos.x != -1)
		{
			sprite = map->sprites[t.itmp];
			player_dist.x = get_dist(sprite.pos, player->pos);
			if (t.itmp > 0)
			{
				player_dist.y = get_dist(map->sprites[t.itmp - 1].pos, pos);
				if (player_dist.x > player_dist.y && (t.itmp_2 = 1))
					swap_sprite(map, t.itmp, sprite);
			}
		}
	}
}

void	reinit_map(t_data *data)
{
	t_map	*map;
	int		i;

	i = 0;
	map = data->map;
	while (map->walls[i].pos.x != -1)
	{
		reinit_wall(&map->walls[i]);
		i++;
	}
	i = 0;
	while (map->sprites[i].pos.x != -1)
	{
		map->sprites[i].is_visible = 0;
		i++;
	}
}
