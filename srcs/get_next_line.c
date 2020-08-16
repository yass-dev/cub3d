/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:01:07 by yel-alou          #+#    #+#             */
/*   Updated: 2020/02/13 12:09:11 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_free(char *ptr)
{
	free(ptr);
	return (1);
}

int	loop(int fd, int *ret, char *buffer, char **save)
{
	char	*tmp;

	while ((*ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[*ret] = '\0';
		tmp = *save;
		*save = ft_strjoin(*save, &buffer[0]);
		free(tmp);
		if (*save == NULL)
			return (-1);
		if (ft_search_char(*save, '\n') != -1)
			break ;
	}
	if (*ret < 0)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			pos;
	char		*tmp;

	if (check_error(fd, line) < 0 || loop(fd, &ret, buffer, &save) < 0)
		return (-1);
	if ((pos = ft_search_char(save, '\n')) != -1)
	{
		tmp = save;
		*line = cut_str(save, 0, pos - 1);
		save = cut_str(save, pos + 1, ft_strlen(save));
		free(tmp);
		if (!save)
			return (-1);
		return (1);
	}
	*line = (!save || *save == 0 ? ft_strdup("") : ft_strdup(save));
	if (save != NULL && save[0] != '\0')
		free(save);
	if (save != NULL)
		save[0] = '\0';
	return (0);
}

int	check_error(int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	return (1);
}
