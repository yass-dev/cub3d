/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:16:43 by root              #+#    #+#             */
/*   Updated: 2020/04/27 12:16:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(t_flag *flag, char c)
{
	if (c == '0')
		set_width_char(flag, '0');
	else if (c == '-')
		set_left(flag, 1);
	else if (c == '+')
		flag->signe = 1;
}

void	set_left(t_flag *flag, int on)
{
	flag->align_left = on;
}

void	set_width(t_flag *flag, int width)
{
	if (width < 0)
	{
		flag->align_left = 1;
		width = width * -1;
	}
	flag->width = width;
}

void	set_width_char(t_flag *flag, char c)
{
	flag->width_char = c;
}

void	set_precision(t_flag *flag, int precision)
{
	if (precision >= 0)
		flag->precision = precision;
}
