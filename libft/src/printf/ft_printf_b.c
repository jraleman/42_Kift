/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:40:03 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:46 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_b(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		handle_width(x, 'b');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 2, "012");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	free(nbr);
	if (x->alt == 1 && org != 0)
		ft_arr_insertn(&x->extra, 0, "0b", 2);
	handle_width(x, 'b');
	return (ft_printf_append(ret, fmt, x));
}
