/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:46:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/12 12:29:37 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	insert_extra(char *buf, char **extra)
{
	char	*tmp;

	if (*extra == 0)
	{
		*extra = ft_strdup(buf);
		ft_bzero(buf, GNL_BUFF_SIZE + 1);
		return ;
	}
	tmp = ft_strjoin(*extra, buf);
	free(*extra);
	ft_bzero(buf, GNL_BUFF_SIZE + 1);
	*extra = tmp;
}

int		assign_line(char **extra, char **line, size_t size)
{
	*line = ft_strndup(*extra, size);
	*extra = ft_memmove(*extra, *extra + size + 1, ft_strlen(*extra));
	return (1);
}

int		final_line(char **extra, char **line)
{
	size_t extra_len;

	extra_len = ft_strlen(*extra);
	*line = ft_strdup(*extra);
	ft_bzero(*extra, extra_len);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[GNL_BUFF_SIZE + 1];
	char			*tmp;
	int				b_read;
	static char		*extra[GNL_MAX_FD];

	if (fd < 0 || !line || GNL_BUFF_SIZE == 0 || fd > GNL_MAX_FD)
		return (-1);
	ft_bzero(buf, GNL_BUFF_SIZE + 1);
	while ((b_read = read(fd, buf, GNL_BUFF_SIZE)) != 0)
	{
		CHK(b_read == -1, -1);
		insert_extra(buf, &extra[fd]);
		if ((tmp = ft_strchr(extra[fd], '\n')) != 0)
			return (assign_line(&extra[fd], line, tmp - extra[fd]));
	}
	if (!extra[fd])
		return (0);
	else if ((tmp = ft_strchr(extra[fd], '\n')) != 0)
		return (assign_line(&extra[fd], line, tmp - extra[fd]));
	else if (ft_strlen(extra[fd]) > 0)
		return (final_line(&extra[fd], line));
	ft_strdel(&extra[fd]);
	return (0);
}
