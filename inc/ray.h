/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:29:29 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:40:22 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "position.h"
# include "utils.h"
# include <math.h>

typedef struct	s_ray
{
	t_pos		pos;
	t_pos		tmp_pos;
	float		angle;
	int			length;
	t_pos		impact_pos;
	int			impact_length;
	int			wall;
	int			id;
	t_pos		step;
	int			wall_side;
	t_list		*sprites;
	int			sprite_id;
	int			sprite_dist;
	t_pos		sprite_impact_pos;
}				t_ray;

void			init_ray(t_ray *ray, t_pos pos, float angle, t_pos id_len);
void			draw_ray(t_ray *ray, t_data *data);
int				is_on_wall(t_pos pos, t_data *data);
int				is_on_sprite(t_pos pos, t_data *data, int h);
int				get_wall_side(t_pos pos, t_data *data, t_pos wall_pos);
void			ray_calcul(t_tmp *tmp, t_pos pos, t_ray *ray);
int				ray_calcul_2(t_tmp tmp, t_pos pos, t_data *d, t_ray *ray);

#endif
