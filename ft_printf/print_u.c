/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:26:54 by root              #+#    #+#             */
/*   Updated: 2020/05/07 19:09:58 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nb_precision(t_flag *flag, unsigned int nb)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_utoa(nb);
	if (flag->precision < ft_strlen(str))
		flag->precision = ft_strlen(str);
	while (i < flag->precision - ft_strlen(str))
	{
		ft_write(1, "0", 1, flag);
		i++;
	}
	ft_putstr(str, flag);
	free(str);
}

static void	print_u_prec(t_flag *flag, unsigned int nb)
{
	int		i;
	char	*str;

	i = 0;
	if (flag->precision != -1 || flag->align_left)
		flag->width_char = ' ';
	if (flag->align_left)
		print_nb_precision(flag, nb);
	str = ft_utoa(nb);
	if (flag->precision < ft_strlen(str))
		flag->precision = ft_strlen(str);
	while (i < flag->width - flag->precision)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		print_nb_precision(flag, nb);
}

static void	print_u_no_prec(t_flag *flag, unsigned int nb)
{
	int		i;
	char	*str_nb;

	i = 0;
	if (flag->align_left || flag->precision != -1)
		flag->width_char = ' ';
	str_nb = (flag->precision == 0 && nb == 0 ? ft_strdup("") : ft_utoa(nb));
	if (flag->align_left)
		ft_putstr(str_nb, flag);
	while (i < flag->width - ft_strlen(str_nb))
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		ft_putstr(str_nb, flag);
	free(str_nb);
}

void		print_u(t_flag *flag, unsigned int nb)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	if (flag->precision != -1 && flag->precision >= ft_strlen(tmp))
		print_u_prec(flag, nb);
	else
		print_u_no_prec(flag, nb);
	free(tmp);
}
