/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:25:42 by root              #+#    #+#             */
/*   Updated: 2020/05/07 06:28:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nb_precision(t_flag *flag, unsigned int nb)
{
	int		i;
	char	*str;

	i = 0;
	str = dec_to_hex(nb);
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

static void	print_x_prec(t_flag *flag, unsigned int nb)
{
	int		i;
	int		nb_signe;

	i = 0;
	nb_signe = flag->signe;
	if (flag->precision != -1 || flag->align_left)
		flag->width_char = ' ';
	if ((flag->width_char == '0' || flag->align_left || flag->precision != -1)
		&& nb_signe)
		ft_write(1, "+", 1, flag);
	if (flag->align_left)
		print_nb_precision(flag, nb);
	while (i < flag->width - flag->precision - nb_signe)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		print_nb_precision(flag, nb);
}

static void	print_x_no_prec(t_flag *flag, unsigned int nb)
{
	int		i;
	char	*str_nb;
	int		nb_signe;

	i = 0;
	nb_signe = flag->signe;
	if (flag->align_left || flag->precision != -1)
		flag->width_char = ' ';
	if ((flag->width_char == '0' || flag->align_left) && nb_signe)
		ft_write(1, "+", 1, flag);
	if (flag->width_char == ' ' && !flag->align_left)
		nb_signe = 0;
	str_nb = (flag->precision == 0 && nb == 0 ? ft_strdup("") : dec_to_hex(nb));
	if (flag->align_left)
		ft_putstr(str_nb, flag);
	while (i < flag->width - ft_strlen(str_nb) - nb_signe)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		ft_putstr(str_nb, flag);
	free(str_nb);
}

void		print_x(t_flag *flag, unsigned int nb)
{
	char *tmp;

	tmp = dec_to_hex(nb);
	if (flag->precision != -1 && flag->precision >= ft_strlen(tmp))
		print_x_prec(flag, nb);
	else
		print_x_no_prec(flag, nb);
	free(tmp);
}
