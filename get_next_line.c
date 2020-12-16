/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:48:10 by kbraum            #+#    #+#             */
/*   Updated: 2020/12/16 17:31:43 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_next_line(char *buf, char **line)
{
	char	*buf_p;
	char	*line_tmp;

	if (*buf)
	{
		line_tmp = *line;
		if ((buf_p = ft_strchr(buf, '\n')))
		{
			*buf_p = '\0';
			*line = ft_strjoin(*line, buf);
			ft_strcpy(buf, buf_p + 1);
		}
		else
		{
			*line = ft_strjoin(*line, buf);
			*buf = '\0';
		}
		free(line_tmp);
	}
	else
		buf_p = 0;
	return (buf_p);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	char		*buf_p;
	int			n;

	if (BUFFER_SIZE < 1 || (n = read(fd, buf, 0)) < 0 || line == 0)
		return (-1);
	*line = ft_strjoin("", "");
	buf_p = check_next_line(buf, line);
	while (buf_p == 0 && (n = read(fd, buf, BUFFER_SIZE)))
	{
		buf[n] = '\0';
		buf_p = check_next_line(buf, line);
		if (*line == 0)
			return (-1);
	}
	return (buf_p == 0 && n == 0 ? 0 : 1);
}
