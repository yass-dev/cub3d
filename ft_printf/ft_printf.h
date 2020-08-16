/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yassou200121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:27:59 by root              #+#    #+#             */
/*   Updated: 2020/05/07 19:48:52 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef unsigned long long int	t_ulli;

typedef struct					s_flag
{
	int							precision;
	char						precision_char;
	int							width;
	char						width_char;
	int							align_left;
	int							signe;
	t_ulli						char_count;
	int							percent_pos;
}								t_flag;

int								ft_printf(const char *format, ...);
int								test_char_type(t_flag *f, va_list *l, char c);
int								is_flag(char c);
int								is_number(char c);
void							set_left(t_flag *flag, int on);
void							set_flag(t_flag *flag, char c);
void							set_width(t_flag *flag, int width);
void							set_width_char(t_flag *flag, char c);
void							set_precision(t_flag *flag, int precision);
char							*cut_str(char *str, int s, int e);
int								ft_atoi(char *str);
char							*ft_itoa(int nb);
char							*ft_utoa(unsigned int nb);
char							*ft_strdup(char *str);
void							ft_putstr(char *str, t_flag *flag);
int								ft_strlen(char *str);
void							print_d(t_flag *flag, int nb);
void							printdnoprec2(t_flag *f, int a, int b, char *s);
void							print_c(t_flag *flag, char c);
void							print_s(t_flag *flag, char *str);
void							print_p(t_flag *flag, void *p);
void							print_p_noprec_2(t_flag *flag, char *str_nb);
void							print_p_null_prec(t_flag *flag);
void							print_p_null_no_prec(t_flag *flag);
void							print_x(t_flag *flag, unsigned int nb);
void							print_x_maj(t_flag *flag, unsigned int nb);
void							print_u(t_flag *flag, unsigned int a);
void							print_pourcent(t_flag *flag, char c);
void							init_flag(t_flag *flag);
char							*ft_strjoin(char *str, char *str2);
char							*ui_to_hex(t_ulli nb, char *base);
char							*dec_to_hex(unsigned int nb);
void							str_to_upper(char *str);
void							ft_write(int fd, char *str, int nb, t_flag *f);
char							*const_to_char(const char *s);
int								is_conversion_char(char c);

#endif
