/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:02:00 by yel-alou          #+#    #+#             */
/*   Updated: 2020/07/27 14:44:03 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "map.h"

t_player	*init_player(t_data *data)
{
	t_player	*player;
	float		tmp_angle;
	float		i;
	t_ray		*ray;
	t_pos		id_len;

	i = -1.f;
	player = ft_malloc(data, sizeof(t_player));
	player->pos.x = 2 * data->block_size;
	player->pos.y = 2 * data->block_size;
	player->step = 10;
	player->fov = 60;
	player->rays = ft_malloc(data, sizeof(t_ray) * (data->win_size.x));
	player->angle = 00.0;
	player->ex_angle = 0;
	player->height = data->win_size.y / 2;
	id_len.y = data->block_size * 1000;
	while (++i < data->win_size.x)
	{
		id_len.x = (int)i;
		ray = &player->rays[(int)i];
		tmp_angle = i * (float)player->fov / ((float)data->win_size.x);
		init_ray(ray, player->pos, tmp_angle, id_len);
	}
	return (player);
}

void		draw_player(t_data *data)
{
	t_player	*player;
	t_pos		tmp_pos;
	int			i;
	int			j;

	i = 0;
	player = data->player;
	tmp_pos = player->pos;
	tmp_pos.x /= data->block_size;
	tmp_pos.x *= data->minimap_wall_size;
	tmp_pos.y /= data->block_size;
	tmp_pos.y *= data->minimap_wall_size;
	i = tmp_pos.x;
	while (i < tmp_pos.x + data->minimap_wall_size)
	{
		j = tmp_pos.y;
		while (j < tmp_pos.y + data->minimap_wall_size)
			j++;
		i++;
	}
	i = -1;
	while (++i < data->win_size.x)
		draw_ray(&player->rays[i], data);
}

void		move_player(t_player *pl, int direction, t_data *data)
{
	int		i;
	t_pos	tmp_pos;
	float	angle;

	i = -1;
	angle = pl->angle;
	if (direction == KEY_RIGHT || direction == KEY_LEFT)
		angle += 90;
	tmp_pos.x = cos(dtor(angle)) * pl->step;
	tmp_pos.y = sin(dtor(angle)) * pl->step;
	if ((direction == KEY_DOWN || direction == KEY_LEFT)
		&& (tmp_pos.x *= -1) == tmp_pos.x)
		tmp_pos.y *= -1;
	pl->ex_pos = pl->pos;
	pl->pos.x += tmp_pos.x;
	pl->pos.y += tmp_pos.y;
	if (is_on_wall(pl->pos, data) != -1)
		pl->pos = pl->ex_pos;
	while (++i < data->win_size.x)
		pl->rays[i].pos = pl->pos;
	pl->ex_angle = pl->angle;
}

void		rotate_player(t_player *player, float angle)
{
	player->ex_angle = player->angle;
	player->angle += angle;
}

void		player_drop_stand(t_data *data, t_player *player, int sens)
{
	if (sens == 257 && (player->height == data->win_size.y / 2
		|| player->height == data->win_size.y / 2 + 10))
		player->height -= 10;
	else if (sens == 49 && (player->height == data->win_size.y / 2
			|| player->height == data->win_size.y / 2 - 10))
		player->height += 10;
}
