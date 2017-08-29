/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 08:32:33 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 16:20:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_log_err(char *file, int line, char *message, ...)
{
	int		fd;
	char	*str_errno;
	va_list	ap;

	str_errno = errno == 0 ? "None" : strerror(errno);
	fd = fileno(stderr);
	va_start(ap, message);
	ft_dprintf(fd, "%{red}[ERROR] (%s:%d: errno: %s): ", file, line, str_errno);
	ft_vdprintf(fd, message, ap);
	ft_dprintf(fd, "%{eoc}\n");
	errno = 0;
	return (-1);
}

int		ft_log_debug(char *file, int line, char *message, ...)
{
	int			fd;
	va_list		ap;

	fd = fileno(stderr);
	va_start(ap, message);
	ft_dprintf(fd, "%{green}[DEBUG] %s:%d: ", file, line);
	ft_vdprintf(fd, message, ap);
	ft_dprintf(fd, "%{eoc}\n");
	return (0);
}
