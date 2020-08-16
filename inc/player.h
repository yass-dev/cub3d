/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:02:14 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:39:46 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_SIZE 10

# include <stdlib.h>
# include "position.h"
# include "utils.h"
# include "ray.h"

typedef struct	s_player
{
	t_pos		pos;
	t_pos		ex_pos;
	float		angle;
	float		ex_angle;
	int			fov;
	int			height;
	int			step;
	t_ray		*rays;
	int			rays_nb;
}				t_player;

t_player		*init_player(t_data *data);
void			draw_player(t_data *data);
void			move_player(t_player *pl, int direction, t_data *data);
void			rotate_player(t_player *player, float angle);
void			player_drop_stand(t_data *d, t_player *player, int sens);

#endif
