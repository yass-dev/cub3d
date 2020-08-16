/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:10:02 by yel-alou          #+#    #+#             */
/*   Updated: 2020/08/13 11:01:57 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "map.h"
#include "events.h"
#include "player.h"
#include "sprite.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 1 && ft_printf("Erreur: le programme n'a pas recu de map !\n"))
		exit(0);
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		data.save = 1;
	else
		data.save = 0;
	check_map_name(&data, argv[1]);
	init_key_map(&data);
	check_double(&data, open(argv[1], O_RDONLY));
	init(&data, argv[1]);
	mlx_do_key_autorepeaton(data.mlx_ptr);
	manage_keyboard(KEY_UP, &data);
	mlx_mouse_hook(data.win_ptr, &manage_mouse, &data);
	mlx_key_hook(data.win_ptr, &manage_keyboard, &data);
	mlx_expose_hook(data.win_ptr, &manage_expose, &data);
	mlx_hook(data.win_ptr, 17, 131072, exit_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
