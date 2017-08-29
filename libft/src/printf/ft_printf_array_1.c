/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_array_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:01:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_arr_init(t_printf_arr *src, size_t cap)
{
	if (src == 0 || cap == 0)
		return (-1);
	ft_bzero(src, sizeof(t_printf_arr));
	CHK((src->ptr = ft_memalloc(cap)) == NULL, -1);
	src->cap = cap;
	src->len = 0;
	return (0);
}

int8_t	ft_arr_sizechk(t_printf_arr *src, size_t sze)
{
	CHK(src == 0, -1);
	CHK(src->cap == 0, -1);
	if (sze + src->len > src->cap)
		CHK(ft_arr_resize(src, sze) == -1, -1);
	return (0);
}

int8_t	ft_arr_resize(t_printf_arr *src, size_t sze)
{
	size_t	malloc_sze;
	void	*tmp;

	malloc_sze = src->cap;
	CHK(src == 0, -1);
	CHK(src->cap == 0, -1);
	if (sze + src->len > malloc_sze)
	{
		while (sze + src->len > malloc_sze)
			malloc_sze *= 2;
		CHK((tmp = ft_memalloc(malloc_sze)) == 0, -1);
		if (src->len != 0)
			ft_memcpy(tmp, src->ptr, src->len);
		free(src->ptr);
		src->ptr = tmp;
		src->cap = malloc_sze;
	}
	return (0);
}

int8_t	ft_arr_insertn(t_printf_arr *dst, size_t index,
		const void *src, size_t src_len)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK((ft_arr_sizechk(dst, src_len) == -1), -1);
	if (index < dst->len)
		ft_memmove(&dst->ptr[index + src_len],
				&dst->ptr[index], dst->len - index);
	ft_memcpy(&dst->ptr[index], src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_arr_appendn(t_printf_arr *dst, const void *src, size_t n)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK(ft_arr_sizechk(dst, n) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src, n);
	dst->len += n;
	return (0);
}
