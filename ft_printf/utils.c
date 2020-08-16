/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:27:41 by root              #+#    #+#             */
/*   Updated: 2020/08/13 10:58:45 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		test_char_type(t_flag *flag, va_list *list, char c)
{
	if (c == 'd' || c == 'i')
		print_d(flag, va_arg(*list, int));
	else if (c == 'c')
		print_c(flag, va_arg(*list, int));
	else if (c == 's')
		print_s(flag, va_arg(*list, char*));
	else if (c == 'p')
		print_p(flag, va_arg(*list, void*));
	else if (c == 'x')
		print_x(flag, va_arg(*list, unsigned int));
	else if (c == 'X')
		print_x_maj(flag, va_arg(*list, unsigned int));
	else if (c == 'u')
		print_u(flag, va_arg(*list, unsigned int));
	else if (c == '%')
		print_pourcent(flag, c);
	else if (c != '\0')
		print_pourcent(flag, c);
	return (1);
}
