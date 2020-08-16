/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:46:07 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/13 10:46:01 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	int_in_uchar(unsigned char *s, int i)
{
	s[0] = (unsigned char)i;
	s[1] = (unsigned char)(i >> 8);
	s[2] = (unsigned char)(i >> 16);
	s[3] = (unsigned char)(i >> 24);
}

void	bmp_write_header(t_data *data, int fd, int size)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_in_uchar(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_in_uchar(header + 18, data->win_size.x);
	int_in_uchar(header + 22, data->win_size.y);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	if (write(fd, header, 54) != 54)
		ft_exit(data, "Error\nwhile creating bitmap !");
}

void	bmp_write_pixels(t_data *data, int fd)
{
	int		x;
	int		y;
	int		color;
	t_pos	size;

	x = 0;
	y = data->win_size.y;
	size = data->win_size;
	while (--y >= 0)
	{
		x = 0;
		while (x < data->win_size.x)
		{
			color = *(int*)(data->img_addr + (x + y * size.x) * data->bpp / 8);
			if (write(fd, &color, 3) != 3)
				ft_exit(data, "Error\nwhile creating bitmap !");
			x++;
		}
	}
}

int		save(t_data *data)
{
	int		size;
	int		fd;
	char	*filename;

	filename = ft_strdup("screenshots/first_image.bmp");
	ft_printf("Saving screenshot at %s...\n", filename);
	size = 54 + (data->win_size.x * data->win_size.y * 3);
	if ((fd = open(filename, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR)) < 0)
	{
		free(filename);
		ft_exit(data, "Error\ncannot save bmp file !");
	}
	bmp_write_header(data, fd, size);
	bmp_write_pixels(data, fd);
	close(fd);
	free(filename);
	return (1);
}
