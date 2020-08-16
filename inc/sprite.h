/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:03:17 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:39:59 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <mlx.h>
# include <stdlib.h>
# include "utils.h"
# include "position.h"
# include "get_next_line.h"

typedef struct	s_sprite
{
	t_image		image;
	t_pos		pos;
	int			width;
	int			height;
	int			ray_id;
	int			distance;
	int			is_visible;
}				t_sprite;

void			init_sprite(t_sprite *s, char *filename, t_data *data);
void			set_sprites_not_drawable();
void			reinit_sprite(t_sprite *sprite);

#endif
