/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:24:14 by root              #+#    #+#             */
/*   Updated: 2020/05/07 18:04:58 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_3(int *i, char *f, t_flag *flag, va_list *list)
{
	int		j;
	char	*tmp;

	if (f[*i] == '.')
	{
		j = *i + 1;
		if (f[j] == '*')
		{
			set_precision(flag, va_arg(*list, int));
			j++;
		}
		else
		{
			while (is_number(f[j]))
				j++;
			tmp = cut_str(f, (*i) + 1, j - 1);
			set_precision(flag, ft_atoi(tmp));
			free(tmp);
		}
		*i = j;
	}
	if (flag->percent_pos == *i - 1 && !is_conversion_char(f[*i]))
		ft_write(1, "%", 1, flag);
	test_char_type(flag, list, f[*i]);
}

void	ft_printf_2(int *i, t_flag *flag, char *format, va_list *list)
{
	int		j;
	char	*tmp;

	init_flag(flag);
	while (is_flag(format[++(*i)]) && format[*i] != '\0')
		set_flag(flag, format[*i]);
	j = *i;
	while (is_number(format[j]) && format[j] != '\0')
		j++;
	tmp = cut_str(format, *i, j - 1);
	set_width(flag, ft_atoi(tmp));
	free(tmp);
	*i = j;
	if (format[*i] == '*')
	{
		set_width(flag, va_arg(*list, int));
		(*i)++;
	}
	ft_printf_3(i, format, flag, list);
}

char	*init_ft_printf(const char **f, int *count, int *i)
{
	*count = 0;
	*i = 0;
	return (const_to_char(*f));
}

void	print_char(char c, t_flag *flag, int *count)
{
	ft_write(1, &c, 1, flag);
	*count += 1;
}

int		ft_printf(const char *f, ...)
{
	va_list	list;
	int		i;
	char	*format;
	int		count;
	t_flag	flag;

	va_start(list, f);
	format = init_ft_printf(&f, &count, &i);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flag.percent_pos = i;
			ft_printf_2(&i, &flag, format, &list);
			count += flag.char_count;
			flag.char_count = 0;
		}
		else
			print_char(format[i], &flag, &count);
		i = (!format[i] ? i : i + 1);
	}
	va_end(list);
	free(format);
	return (count);
}
