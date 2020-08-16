/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:24:23 by root              #+#    #+#             */
/*   Updated: 2020/04/27 12:24:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_flag *flag, char c)
{
	int		i;

	i = 0;
	if (flag->align_left)
		flag->width_char = ' ';
	if (flag->align_left)
		ft_write(1, &c, 1, flag);
	while (i < flag->width - 1)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		ft_write(1, &c, 1, flag);
}
