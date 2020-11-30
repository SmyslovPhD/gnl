/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:15:20 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/30 21:28:05 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct			s_list_buf
{
	int					fd;
	char				buf[BUFFER_SIZE + 1];
	struct s_list_buf	*next;
}						t_list_buf;

int						get_next_line(int fd, char **line);
char					*ft_strjoin(const char *s1, char const *s2);
char					*ft_strcpy(char *dst, char const *src);
char					*ft_strchr(char const *s, int c);
char					*ft_strnew(size_t n);

#endif
