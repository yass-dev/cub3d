/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:25:22 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:39:17 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_vector2f
{
	float	x;
	float	y;
}				t_vector2f;

int				pos_equal(t_pos pos1, t_pos pos2);

#endif
