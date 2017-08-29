/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:35:34 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:52 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_f(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	(void)ret;
	(void)fmt;
	(void)x;
	(void)clone;
	return (0);
}

intmax_t	*ft_printf_n_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
		return ((intmax_t *)va_arg(clone, int *));
	if (x->len_mod == 1)
		return ((intmax_t *)va_arg(clone, signed char *));
	if (x->len_mod == 2)
		return ((intmax_t *)va_arg(clone, short *));
	if (x->len_mod == 3)
		return ((intmax_t *)va_arg(clone, long *));
	if (x->len_mod == 4)
		return ((intmax_t *)va_arg(clone, long long *));
	if (x->len_mod == 5)
		return ((intmax_t *)va_arg(clone, intmax_t *));
	if (x->len_mod == 6)
		return ((intmax_t *)va_arg(clone, ssize_t *));
	return (0);
}

int8_t		ft_printf_n(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	intmax_t	*i;
	int			tmp;

	tmp = ret->len;
	i = ft_printf_n_len(x, clone);
	*i = (intmax_t)tmp;
	++*fmt;
	return (0);
}
