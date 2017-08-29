/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:53:24 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:53 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 6 is the length of (null) string.
*/

size_t	ft_wcslen(wchar_t *wstr)
{
	size_t	len;
	wchar_t	*p;

	if (wstr == NULL)
		return (6);
	p = wstr;
	while (*p != 0)
		p++;
	len = (char *)p - (char *)wstr;
	return (len);
}

int8_t	ft_printf_wstr(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	wchar_t	*tmp;
	char	*final;
	int		len;
	int		i;
	int		k;

	tmp = va_arg(clone, wchar_t*);
	len = (x->is_prec == 1) ? MIN(x->prec, (int)ft_wcslen(tmp))
		: ft_wcslen(tmp);
	final = (tmp != NULL) ? ft_strnew(len) : ft_strdup("(null)");
	i = (tmp != NULL) ? 0 : len;
	while (tmp && *tmp != 0)
	{
		k = ft_wctomb(&final[i], *tmp);
		if (k + i > len)
			break ;
		i += k;
		++tmp;
	}
	ft_arr_appendn(&x->extra, final, sizeof(char) * i);
	free(final);
	handle_width(x, 's');
	return (ft_printf_append(ret, fmt, x));
}

/*
** 'S' is treated as s with l modifider.
*/

int8_t	ft_printf_s(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	char	*tmp;
	char	*final;
	int		n;

	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	if (**fmt == 'S' || x->len_mod == 3)
		return (ft_printf_wstr(ret, fmt, x, clone));
	tmp = va_arg(clone, char*);
	final = (tmp != NULL) ? ft_strdup(tmp) : ft_strdup("(null)");
	n = (x->is_prec == 1) ? MIN(x->prec, (int)ft_strlen(final))
		: ft_strlen(final);
	ft_arr_appendn(&x->extra, final, sizeof(char) * n);
	free(final);
	handle_width(x, 's');
	return (ft_printf_append(ret, fmt, x));
}
