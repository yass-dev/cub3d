/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:43:31 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/14 12:19:39 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "position.h"
# include "libft.h"
# include "ft_printf.h"

# define PI 3.14159265359
# define BLOCK_SIZE 64

# define KEY_UP 13
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_R 123
# define KEY_T 124
# define KEY_ESCAPE 53
# define MIN_WIDTH 512
# define MIN_HEIGHT 256
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct	s_image
{
	void	*image;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_tmp
{
	int		itmp;
	int		itmp_2;
	int		itmp_3;
	int		itmp_4;
	int		itmp_5;
	char	*ctmp;
	char	*ctmp_2;
	char	*ctmp_3;
	char	*ctmp_4;
	char	**cctmp;
	char	**cctmp_2;
	float	ftmp;
	float	ftmp_1;
	float	ftmp_2;
	float	ftmp_3;
	float	ftmp_4;
	float	ftmp_5;
}				t_tmp;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*map;
	t_image	textures[4];
	void	*image;
	char	*img_addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		size_line;
	int		endian;
	int		block_size;
	int		minimap_wall_size;
	int		screen_dist;
	t_pos	win_size;
	int		save;
	int		ground_color;
	int		ceiling_color;
	t_pos	map_size;
	t_pos	sz;
	t_tmp	tmp;
	t_list	*list;
	t_pos	img_size;
	short	r;
	short	no;
	short	ea;
	short	we;
	short	so;
	short	s;
	short	c;
	short	f;
}				t_data;

int				init(t_data *data, char *str);
void			init_image(t_data *data, t_image *image);
void			put_pixel(void *mlx, void *win, int x, int y, int c, int s);
void			put_pxl_img(t_data *data, int x, int y, int color);
void			clear_img(t_data *data);
int				get_pxl_color(t_image image, int x, int y);
float			dtor(int deg);
int				ft_abs(int a);
char			*remove_white_space(char *line);
int				contains_only_wall_char(char *str);
int				count_sprites(char *str);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
int				ft_lstsize(t_list *list);
void			clear_image(t_data *data);
void			ft_exit(t_data *data, char *str);
int				ft_strcmp(char *str, char *str2);
int				contains_only_char(char *str, char c);
int				exit_hook(void *param);
void			*ft_malloc(t_data *data, int n);
void			mlx_get_screen_size(void *s, int *a, int *b);
int				ft_free(void *s);
int				free_arr(char **arr);
int				only_white_space(char *str);
void			check_map_name(t_data *data, char *str);
void			init_key_map(t_data *data);
void			check_double(t_data *data, int fd);
void			check_double_2(t_data *data, char *line);
int				gncp(char *line, int pos);
int				arr_size(char **arr);
int				sis(t_data *data, t_pos pos);
int				line_is_null(char *str);

#endif
