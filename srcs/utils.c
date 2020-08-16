/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:37:04 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/13 11:02:13 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map.h"
#include "player.h"

void		init_2(t_data *data, t_map *map, t_player *player)
{
	t_pos	s;
	t_data	*d;
	int		*sz;

	s = data->win_size;
	d = data;
	sz = &d->size_line;
	if (data->mlx_ptr == NULL || data->win_ptr == NULL)
		ft_exit(data, "Error\nmlx null !");
	data->image = mlx_new_image(data->mlx_ptr, s.x, s.y);
	data->img_width = data->win_size.x;
	data->img_height = data->win_size.y;
	d->img_addr = mlx_get_data_addr(d->image, &d->bpp, sz, &d->endian);
	if (data->image == NULL)
		ft_exit(data, "Error\nimage null !");
	data->minimap_wall_size = data->win_size.x / 100;
	mlx_get_screen_size(data->mlx_ptr, &data->sz.x, &data->sz.y);
	map = data->map;
	data->player = init_player(data);
	player = data->player;
	player->pos = map->player_pos;
	player->angle = map->player_angle;
}

int			init(t_data *data, char *filename)
{
	int			fd;
	t_pos		sz;
	t_data		*d;

	data->mlx_ptr = mlx_init();
	fd = open(filename, O_RDONLY);
	d = data;
	d->list = malloc(sizeof(t_list));
	d->list->next = NULL;
	if (fd < 0 && ft_printf("Error\ncannot open map !\n"))
		exit(0);
	mlx_get_screen_size(data->mlx_ptr, &data->sz.x, &data->sz.y);
	sz = data->sz;
	data->map = create_map(fd, filename, data);
	if (sis(data, sz) && (data->win_size.x < MIN_WIDTH
		|| data->win_size.x > sz.x || data->win_size.y < MIN_HEIGHT
		|| data->win_size.y > sz.y) && (data->win_size.x = sz.x))
		data->win_size.y = sz.y;
	sz = data->win_size;
	d->win_ptr = mlx_new_window(d->mlx_ptr, sz.x, sz.y, "cub3D");
	init_2(data, NULL, NULL);
	return (1);
}

void		init_image(t_data *data, t_image *i)
{
	t_pos	s;

	s = data->win_size;
	i->image = mlx_new_image(data->mlx_ptr, s.x, s.y);
	i->width = data->win_size.x;
	i->height = data->win_size.y;
	i->addr = mlx_get_data_addr(i->image, &i->bpp, &i->size_line, &i->endian);
}

float		dtor(int deg)
{
	return (deg * PI / 180);
}

void		put_pxl_img(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = ((y * data->img_width + x) * data->bpp / 8);
	if (x < data->win_size.x && y < data->win_size.y)
		*(int*)(data->img_addr + offset) = color;
}
