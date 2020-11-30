/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:48:10 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/30 21:22:58 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_buf(int fd, t_list_buf **list_buf)
{
	t_list_buf	*elem;

	elem = *list_buf;
	while (elem)
	{
		if (fd == elem->fd)
			return (elem->buf);
		elem = elem->next;
	}
	elem = malloc(sizeof(t_list_buf));
	if (elem == 0)
		return (0);
	elem->fd = fd;
	*(elem->buf) = '\0';
	elem->next = *list_buf;
	*list_buf = elem;
	return (elem->buf);
}

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
	static t_list_buf	*list_buf = 0;
	char				*buf;
	char				*buf_p;
	int					n;

	buf = find_buf(fd, &list_buf);
	if ((n = read(fd, buf, 0)) < 0 || line == 0 || buf == 0)
		return (-1);
	*line = ft_strjoin("", "");
	buf_p = check_next_line(buf, line);
	while (buf_p == 0 && (n = read(fd, buf, BUFFER_SIZE)))
	{
		buf[n] = '\0';
		buf_p = check_next_line(buf, line);
	}
	return (buf_p == 0 && n == 0 ? 0 : 1);
}
