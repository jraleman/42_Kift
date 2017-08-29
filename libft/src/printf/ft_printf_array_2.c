/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_array_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:25:44 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:45 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_arr_append_arr(t_printf_arr *dst, t_printf_arr *src)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK(ft_arr_sizechk(dst, src->len) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src->ptr, src->len);
	dst->len += src->len;
	return (0);
}

void	ft_arr_del(t_printf_arr *src)
{
	if (src == 0)
		return ;
	if (src->cap > 0)
		free(src->ptr);
	ft_bzero(src, sizeof(t_printf_arr));
}

char	*ft_arrtostr(t_printf_arr *src)
{
	CHK(src == 0, 0);
	CHK(src->cap == 0, 0);
	return (src->ptr);
}

int8_t	ft_printf_append(t_printf_arr *ret, const char **fmt, t_printf *x)
{
	CHK2((ft_arr_append_arr(ret, &x->extra)) == -1,
			ft_arr_del(ret), ft_arr_del(&x->extra), -1);
	ft_arr_del(&x->extra);
	++*fmt;
	return (ret->len);
}

int8_t	ft_printf_init(t_printf *x)
{
	ft_bzero(x, sizeof(t_printf));
	x->pad = ' ';
	return (0);
}
