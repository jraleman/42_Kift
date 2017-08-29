/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:59:04 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*ret;
	int			len;

	if (fmt == 0 || *fmt == 0)
		return (0);
	va_start(ap, fmt);
	CHK((len = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(1, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_sprintf(char *ret, const char *fmt, ...)
{
	va_list		ap;
	char		*tmp;
	int			len;

	va_start(ap, fmt);
	if (*fmt == 0)
		ret[0] = 0;
	CHK((len = ft_vasprintf(&tmp, fmt, ap)) == -1, -1);
	ft_strncpy(ret, tmp, len);
	va_end(ap);
	return (len);
}

int		ft_snprintf(char *ret, size_t size, const char *fmt, ...)
{
	va_list		ap;
	char		*tmp;
	ssize_t		len;

	va_start(ap, fmt);
	if (size - 1 == 0)
		ret[0] = 0;
	CHK((len = ft_vasprintf(&tmp, fmt, ap)) == -1, -1);
	ft_strncpy(ret, tmp, MIN(len, (int)(size - 1)));
	va_end(ap);
	return (len);
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, fmt);
	CHK((len = ft_vasprintf(ret, fmt, ap)) == -1, -1);
	va_end(ap);
	return (len);
}

int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	int			len;
	va_list		clone;

	if (*fmt == 0)
		*ret = ft_strnew(0);
	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == NULL)
	{
		*ret = ft_strdup(fmt);
		return (ft_strlen(fmt));
	}
	va_copy(clone, ap);
	len = ft_printf_dispatch(ret, fmt, clone);
	va_end(clone);
	return (len);
}
