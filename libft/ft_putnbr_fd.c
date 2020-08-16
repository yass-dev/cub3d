/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:26 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/15 10:20:37 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int		get_nb_digits(int nb)
{
	int count;

	count = 0;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	get_digit(int nb, int pos)
{
	while (pos--)
	{
		nb /= 10;
	}
	return (nb % 10) + '0';
}

void	print_nb(int current_digit, int can_draw, int nb, int fd)
{
	char	lettre;

	while (current_digit >= 0 && can_draw == 1)
	{
		lettre = get_digit(nb, current_digit);
		write(fd, &lettre, 1);
		current_digit--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	int				current_digit;
	int				can_draw;

	can_draw = 1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		if (nb == -2147483648)
		{
			ft_putstr("2147483648", fd);
			can_draw = 0;
			nb = 0;
		}
		nb *= -1;
	}
	if (nb == 0 && can_draw == 1)
		write(fd, "0", 1);
	current_digit = get_nb_digits(nb) - 1;
	print_nb(current_digit, can_draw, nb, fd);
}
