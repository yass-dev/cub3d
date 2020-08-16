/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:05:43 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 14:34:46 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	init_sprite(t_sprite *sprite, char *filename, t_data *data)
{
	t_image	m;
	t_pos	s;

	if (open(filename, O_RDONLY) < 0)
		ft_exit(data, "Error\nwhile loading sprite texture !");
	m.image = mlx_xpm_file_to_image(data->mlx_ptr, filename, &s.x, &s.y);
	sprite->width = s.x;
	sprite->height = s.y;
	m.width = sprite->width;
	m.height = sprite->height;
	m.addr = mlx_get_data_addr(m.image, &m.bpp, &m.size_line, &m.endian);
	sprite->image = m;
	sprite->is_visible = 0;
}
