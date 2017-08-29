/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:57:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include <libft.h>
# include "printfarray.h"
# define ISWIDTH(a) (a > 48 && a <= 57)
# define ISSIGN(a) (a == '+' || a == '-')
# define ISFLAG(a) (a == '+' || a == '-' || a == ' ' || a == '#' || a == '0')

/*
** Flags
*/

int8_t	ft_printf_flags(t_printf_arr *r, const char **f,
		t_printf *x, va_list c);

/*
** Width
*/

int8_t	ft_printf_width(t_printf_arr *r, const char **f,
		t_printf *x, va_list c);
int8_t	handle_width(t_printf *x, char c);

/*
** Precision
*/

int8_t	ft_printf_dot(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list c);
int8_t	handle_prec(t_printf *x, intmax_t org);

/*
** Length
*/

int8_t	ft_printf_length(t_printf_arr *r, const char **f,
		t_printf *x, va_list c);

/*
** Functions
*/

int		ft_printf_dispatch(char **final, const char *fmt, va_list clone);
int8_t	ft_printf_init(t_printf *x);
int8_t	ft_printf_append(t_printf_arr *ret, const char **fmt, t_printf *x);
int8_t	ft_printf_c(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_b(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_d(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_p(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_s(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_o(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_u(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_n(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_x(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_f(t_printf_arr *r, const char **f, t_printf *x, va_list c);
int8_t	ft_printf_color(t_printf_arr *r, const char **f,
		t_printf *x, va_list c);
int8_t	ft_printf_percent(t_printf_arr *r, const char **f,
		t_printf *x, va_list c);
#endif
