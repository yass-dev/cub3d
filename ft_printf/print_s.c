/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:27:01 by root              #+#    #+#             */
/*   Updated: 2020/05/07 16:27:38 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_str(t_flag *flag, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < flag->precision)
	{
		ft_write(1, &str[i], 1, flag);
		i++;
	}
}

void		print_s(t_flag *flag, char *str)
{
	int		i;
	int		is_null;

	i = -1;
	is_null = 0;
	if (str == NULL)
	{
		if (flag->precision < ft_strlen("(null)") && flag->precision != -1)
			str = ft_strdup("(null)");
		else
			str = ft_strdup("(null)");
		is_null = 1;
	}
	if (flag->precision == -1 || flag->precision > ft_strlen(str))
		flag->precision = ft_strlen(str);
	flag->width_char = ' ';
	if (flag->align_left)
		print_str(flag, str);
	while (++i < flag->width - flag->precision)
		ft_write(1, &flag->width_char, 1, flag);
	if (!flag->align_left)
		print_str(flag, str);
	if (is_null)
		free(str);
}
