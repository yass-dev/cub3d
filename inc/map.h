/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:12:18 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:43:18 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "get_next_line.h"
# include "wall.h"
# include "utils.h"
# include "sprite.h"
# include "ray.h"

typedef struct	s_map
{
	t_wall		*walls;
	int			wall_number;
	t_sprite	*sprites;
	int			sprite_number;
	t_wall		first_free_space;
	t_pos		player_pos;
	float		player_angle;
	char		*str;
}				t_map;

t_map			*create_map(int fd, char *filename, t_data *data);
int				get_wall_number(char *filename);
int				get_sprite_number(char *filename);
void			draw_map(t_data *data);
void			draw_wall(t_data *data);
void			draw_column(t_data *data, int x, int height);
void			draw_column_tex(t_data *data, int x, int height, int side);
void			draw_sprite_column(t_data *data, int x, int h, t_sprite p);
void			draw_sprite(t_data *data);
void			sort_sprites(t_data *data, t_sprite sprite, t_tmp t);
void			reinit_map(t_data *data);
void			load_wall_texture(t_data *data, char *line, int code);
t_map			*sub_init_map(t_tmp *t, t_data *data, char *filename);
int				map_parse(char **sprite_filename, t_tmp *t, t_data *data);
int				map_parse_2(t_tmp *t, t_data *data);
int				map_parse_3(t_tmp *t, t_map *map, t_data *data);
int				map_parse_4(t_tmp *t, t_map *map, t_data *data);
int				map_parse_5(t_tmp *t, t_map *map, t_data *data, char *sfile);
int				map_parse_6(t_map *map, t_data *d, t_tmp t);
void			load_wall_texture(t_data *data, char *line, int code);
int				get_wall_number(char *filename);
int				get_sprite_number(char *filename);
void			draw_map(t_data *data);
void			draw_wall(t_data *d);
void			draw_column_tex(t_data *data, int x, int height, int dir);
void			p(t_data *data, int x, int y, int c);
void			draw_sprite_2(t_data *d, t_sprite s, t_vector2f c, t_pos hx);
t_pos			int_to_pos(int x, int y);
int				get_dist(t_pos p, t_pos pos);
void			swap_sprite(t_map *map, int i, t_sprite sprite);
void			sort_sprites(t_data *data, t_sprite sprite, t_tmp t);
void			reinit_map(t_data *data);

#endif
