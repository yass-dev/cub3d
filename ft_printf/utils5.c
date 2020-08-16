/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:57:13 by root              #+#    #+#             */
/*   Updated: 2020/08/13 10:59:40 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*const_to_char(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		is_conversion_char(char c)
{
	if (!(c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p'
		|| c == 'x' || c == 'X' || c == 'u' || c == '%' || c == '\0'))
		return (0);
	return (1);
}

void	print_p_null_no_prec(t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - 3)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
}

void	print_p_null_prec(t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - flag->precision - 2)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
}
