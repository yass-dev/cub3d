/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:24:48 by root              #+#    #+#             */
/*   Updated: 2020/05/07 18:41:36 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_p_precision(t_flag *flag, void *ptr)
{
	unsigned long long int	addr;
	int						i;
	char					*str;

	i = 0;
	addr = (intptr_t)ptr;
	str = ui_to_hex(addr, "0123456789abcdef");
	ft_write(1, "0x", 2, flag);
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

static void	print_p_prec(t_flag *flag, void *ptr)
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
		print_p_precision(flag, ptr);
	while (i < flag->width - flag->precision - nb_signe - 2)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
		print_p_precision(flag, ptr);
}

static void	print_p_no_prec(t_flag *flag, void *ptr)
{
	int						i;
	char					*str_nb;
	int						nb_signe;
	unsigned long long int	nb;

	i = 0;
	nb = (intptr_t)ptr;
	nb_signe = flag->signe;
	if (flag->align_left)
		flag->width_char = ' ';
	if ((flag->width_char == '0' || flag->align_left) && nb_signe)
		ft_write(1, "+", 1, flag);
	if (flag->width_char == ' ' && !flag->align_left)
		nb_signe = 0;
	str_nb = ui_to_hex(nb, "0123456789abcdef");
	if (flag->width_char == '0' || flag->align_left)
		ft_write(1, "0x", 2, flag);
	if (flag->align_left)
		ft_putstr(str_nb, flag);
	while (i < flag->width - ft_strlen(str_nb) - nb_signe - 2)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	print_p_noprec_2(flag, str_nb);
}

void		print_null_p(t_flag *flag)
{
	int	i;

	i = 0;
	if (!flag->align_left && flag->precision != -1)
		print_p_null_prec(flag);
	else if (!flag->align_left && flag->precision == -1)
		print_p_null_no_prec(flag);
	i = 0;
	ft_write(1, "0x", 2, flag);
	if (flag->precision != -1)
		while (i < flag->precision)
		{
			ft_write(1, "0", 1, flag);
			i++;
		}
	else
		ft_write(1, "0", 1, flag);
	if (flag->align_left && flag->precision != -1)
		print_p_null_prec(flag);
	else if (flag->align_left && flag->precision == -1)
		print_p_null_no_prec(flag);
}

void		print_p(t_flag *flag, void *ptr)
{
	if (ptr == NULL)
	{
		print_null_p(flag);
		return ;
	}
	if (flag->precision > 0)
		print_p_prec(flag, ptr);
	else
		print_p_no_prec(flag, ptr);
}
