/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:10:27 by yel-alou          #+#    #+#             */
/*   Updated: 2020/07/15 17:13:40 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
int		check_error(int fd, char **line);
int		ft_search_char(char *str, char c);
char	*cut_str(char *str, int s, int e);
int		my_free(char *ptr);

#endif
