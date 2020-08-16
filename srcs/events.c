/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:05:24 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/12 10:50:18 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "player.h"
#include "sprite.h"

int	manage_keyboard(int key, void *param)
{
	t_data		*data;
	t_player	*player;

	data = (t_data*)param;
	player = data->player;
	if (key == KEY_ESCAPE)
		ft_exit(data, "");
	else if (key == KEY_R)
		rotate_player(player, -2);
	else if (key == KEY_T)
		rotate_player(player, 2);
	else if (key == KEY_UP || key == KEY_RIGHT
			|| key == KEY_DOWN || key == KEY_LEFT)
		move_player(data->player, key, data);
	else if (key == 257 || key == 49)
		player_drop_stand(data, data->player, key);
	draw_game(data);
	return (1);
}

int	manage_mouse(int button, int x, int y, void *param)
{
	t_data	*data;

	button = x;
	x = y;
	data = param;
	return (1);
}

int	manage_expose(void *param)
{
	t_data	*data;

	data = param;
	draw_game(data);
	return (1);
}

int	draw_game(t_data *data)
{
	static int	i = 0;
	t_tmp		t;
	t_sprite	sprite;

	sprite.pos.x = 555;
	t.itmp = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	reinit_map(data);
	sort_sprites(data, sprite, t);
	draw_player(data);
	draw_wall(data);
	draw_map(data);
	draw_sprite(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	if (++i == 1 && data->save)
		if (save(data))
			ft_exit(data, "Screenshot saved !");
	return (1);
}

int	exit_hook(void *param)
{
	t_data	*data;

	data = param;
	ft_exit(data, "");
	return (1);
}
