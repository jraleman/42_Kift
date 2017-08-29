/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:43 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	char		*ret;
	int			len;

	va_start(ap, fmt);
	CHK((len = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(fd, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_vprintf(const char *fmt, va_list ap)
{
	char		*ret;
	int			len;

	CHK((len = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(1, ret, len);
	free(ret);
	return (len);
}

int		ft_vsprintf(char *ret, const char *fmt, va_list ap)
{
	char		*tmp;
	int			len;

	CHK((len = ft_vasprintf(&tmp, fmt, ap)) == -1, -1);
	ft_strncpy(ret, tmp, len);
	return (len);
}

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	char		*ret;
	int			len;

	CHK((len = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(fd, ret, len);
	free(ret);
	return (len);
}
