/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:22:51 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:40:08 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <mlx.h>
# include "position.h"

typedef struct	s_wall
{
	t_pos		pos;
	int			ray_nb;
}				t_wall;

void			reinit_wall(t_wall *wall);

#endif
