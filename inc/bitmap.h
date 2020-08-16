/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:44:13 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:16 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include "get_next_line.h"
# include "utils.h"

typedef struct	s_bmp_header
{
	char	signature[2];
	int		file_size;
	int		reserved;
	int		data_offset;
	int		info_size;
	int		width;
	int		height;
	short	planes;
	short	bpp;
	int		compression;
	int		image_size;
	int		reso_x;
	int		reso_y;
	int		colors;
	int		imp_colors;

}				t_bmp_header;

int				save(t_data *data);
int				get_image_color(t_data *data, int x, int y);

#endif
