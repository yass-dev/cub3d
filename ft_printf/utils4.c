/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:29:34 by root              #+#    #+#             */
/*   Updated: 2020/08/13 10:50:51 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_flag *flag)
{
	ft_write(1, str, ft_strlen(str), flag);
}

void	print_p_noprec_2(t_flag *flag, char *str_nb)
{
	if (!flag->align_left && flag->width_char == ' ')
		ft_write(1, "0x", 2, flag);
	if (!flag->align_left)
		ft_putstr(str_nb, flag);
	free(str_nb);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}

void	printdnoprec2(t_flag *flag, int w, int nb2, char *str_nb)
{
	int		nb_signe;
	int		i;
	int		write_signe;

	i = 0;
	write_signe = w;
	nb_signe = ((flag->signe && nb2 >= 0) || nb2 < 0 ? 1 : 0);
	if (flag->align_left)
	{
		if (write_signe)
			ft_write(1, (nb2 >= 0 ? "+" : "-"), 1, flag);
		ft_putstr(str_nb, flag);
	}
	while (i < flag->width - ft_strlen(str_nb) - nb_signe)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
	{
		if (write_signe)
			ft_write(1, (nb2 >= 0 ? "+" : "-"), 1, flag);
		ft_putstr(str_nb, flag);
	}
}
