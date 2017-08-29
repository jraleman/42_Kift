/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_percent(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	(void)clone;
	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	ft_arr_insertn(&x->extra, 0, "%", 1);
	handle_width(x, '%');
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_wchar(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	int				len;
	char			tmp[5];
	wchar_t			org;

	org = (wchar_t)va_arg(clone, wint_t);
	len = ft_wctomb(tmp, org);
	ft_arr_appendn(&x->extra, tmp, sizeof(char) * len);
	handle_width(x, 'c');
	return (ft_printf_append(ret, fmt, x));
}

/*
** 'C' is treated as c with l modifider.
*/

int8_t		ft_printf_c(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	unsigned char	tmp[1];

	if (**fmt == 'C')
		x->len_mod = 3;
	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	if (x->len_mod == 3)
		return (ft_printf_wchar(ret, fmt, x, clone));
	tmp[0] = (unsigned char)va_arg(clone, int);
	ft_arr_appendn(&x->extra, tmp, 1);
	handle_width(x, 'c');
	return (ft_printf_append(ret, fmt, x));
}
