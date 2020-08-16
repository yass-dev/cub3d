/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:27:49 by root              #+#    #+#             */
/*   Updated: 2020/04/27 14:05:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_dec_2_hex(char **s, int *i, int *l)
{
	*s = ft_strdup("0123456789abcdef");
	*i = 0;
	*l = 0;
}

char	*dec_to_hex(unsigned nb)
{
	int				i;
	int				len;
	unsigned int	nb2;
	char			*base;
	char			*str;

	if (nb == 0)
		return (ft_strdup("0"));
	nb2 = nb;
	init_dec_2_hex(&base, &i, &len);
	while (nb2 != 0)
	{
		nb2 /= 16;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	while (nb != 0)
	{
		str[len - 1 - i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	str[len] = '\0';
	free(base);
	return (str);
}

void	str_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		i++;
	}
}

char	*ft_utoa(unsigned int nb)
{
	char				*new;
	int					i;
	unsigned int		nb2;
	int					j;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	nb2 = nb;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	new = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (nb2 > 0)
	{
		new[i - j - 1] = (nb2 % 10) + '0';
		nb2 /= 10;
		j++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_write(int fd, char *str, int nb, t_flag *flag)
{
	fd = 1;
	write(fd, str, nb);
	flag->char_count += nb;
}
