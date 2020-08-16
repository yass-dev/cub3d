/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:27:44 by root              #+#    #+#             */
/*   Updated: 2020/08/13 10:50:31 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_2(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	init_flag(t_flag *flag)
{
	flag->precision = -1;
	flag->width = -1;
	flag->width_char = ' ';
	flag->align_left = 0;
	flag->signe = 0;
	flag->char_count = 0;
}

char	*ui_to_hex(unsigned long long int a, char *base)
{
	char						*str;
	unsigned long long int		nb;
	int							i;
	int							j;

	i = 0;
	j = 0;
	nb = a;
	if (a == 0)
		return (ft_strdup("0"));
	while (a)
	{
		a /= 16;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	while (nb)
	{
		str[i - j - 1] = base[nb % 16];
		nb /= 16;
		j++;
	}
	str[i] = '\0';
	return (str);
}
