/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:05:26 by yel-alou          #+#    #+#             */
/*   Updated: 2020/07/27 18:48:43 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <mlx.h>
# include <stdio.h>
# include "map.h"
# include "utils.h"
# include "bitmap.h"

int	manage_keyboard(int key, void *param);
int	manage_mouse(int button, int x, int y, void *param);
int	manage_expose(void *param);
int	draw_game(t_data *data);

#endif
