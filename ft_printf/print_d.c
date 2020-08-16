/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:24:37 by root              #+#    #+#             */
/*   Updated: 2020/05/07 19:49:52 by yel-alou         ###   ########.fr       */
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

void		print_d_prec_2(t_flag *flag, int a, unsigned int z, int write_signe)
{
	int				i;
	int				nb_signe;
	int				nb2;
	unsigned int	nb;

	i = 0;
	nb2 = a;
	nb = z;
	nb_signe = ((flag->signe && nb2 >= 0) || nb2 < 0 ? 1 : 0);
	while (i < flag->width - flag->precision - nb_signe)
	{
		ft_write(1, &flag->width_char, 1, flag);
		i++;
	}
	if (!flag->align_left)
	{
		if (write_signe)
			ft_write(1, (nb2 >= 0 ? "+" : "-"), 1, flag);
		print_nb_precision(flag, nb);
	}
}

static void	print_d_prec(t_flag *flag, int nb2)
{
	int				nb_signe;
	int				write_signe;
	unsigned int	nb;

	nb_signe = ((flag->signe && nb2 >= 0) || nb2 < 0 ? 1 : 0);
	write_signe = nb_signe;
	if (flag->align_left || flag->precision != -1)
		flag->width_char = ' ';
	if ((flag->width_char == '0' || flag->align_left) && nb_signe)
	{
		ft_write(1, (nb2 < 0 ? "-" : "+"), 1, flag);
		nb = (nb2 < 0 ? -1 : 1);
		write_signe = 0;
	}
	nb = (nb2 < 0 ? nb2 * -1 : nb2);
	if (flag->align_left)
	{
		if (write_signe)
			ft_write(1, (nb2 >= 0 ? "+" : "-"), 1, flag);
		print_nb_precision(flag, nb);
	}
	print_d_prec_2(flag, nb2, nb, write_signe);
}

static void	print_d_no_prec(t_flag *flag, int nb2)
{
	char			*str_nb;
	int				nb_signe;
	int				write_signe;
	unsigned int	nb;

	nb_signe = ((flag->signe && nb2 >= 0) || nb2 < 0 ? 1 : 0);
	write_signe = nb_signe;
	if (flag->align_left || flag->precision != -1)
		flag->width_char = ' ';
	if ((flag->width_char == '0' || flag->align_left) && nb_signe)
	{
		ft_write(1, (nb2 < 0 ? "-" : "+"), 1, flag);
		nb = (nb2 < 0 ? -1 : 1);
		write_signe = 0;
	}
	nb = (nb2 < 0 ? nb2 * -1 : nb2);
	str_nb = (flag->precision == 0 && nb == 0 ? ft_strdup("") : ft_utoa(nb));
	printdnoprec2(flag, write_signe, nb2, str_nb);
	free(str_nb);
}

void		print_d(t_flag *flag, int nb)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	if (flag->precision != -1 && flag->precision >= ft_strlen(tmp))
		print_d_prec(flag, nb);
	else
		print_d_no_prec(flag, nb);
	free(tmp);
}
