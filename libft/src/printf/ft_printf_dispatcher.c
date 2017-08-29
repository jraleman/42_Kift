/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatcher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:58:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define LEN1 49
#define LEN2 2
#define TYPEFIELD 22

static char		g_tbl[LEN1][LEN2] =
{
	{"-"}, {"+"}, {" "}, {"#"},
	{"0"}, {"*"}, {"1"}, {"2"},
	{"3"}, {"4"}, {"5"}, {"6"},
	{"7"}, {"8"}, {"9"}, {"."},
	{"hh"}, {"h"}, {"ll"}, {"L"},
	{"l"}, {"j"}, {"z"}, {"%"},
	{"c"}, {"C"}, {"d"}, {"D"},
	{"i"}, {"x"}, {"X"}, {"o"},
	{"O"}, {"u"}, {"U"}, {"s"},
	{"S"}, {"p"}, {"e"}, {"E"},
	{"f"}, {"F"}, {"g"}, {"G"},
	{"a"}, {"A"}, {"n"}, {"{"},
	{"b"}};

static int8_t	(*g_func[LEN1]) (t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone) = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags,
	ft_printf_flags, ft_printf_width, ft_printf_width, ft_printf_width,
	ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width,
	ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_dot,
	ft_printf_length, ft_printf_length, ft_printf_length, ft_printf_length,
	ft_printf_length, ft_printf_length, ft_printf_length, ft_printf_percent,
	ft_printf_c, ft_printf_c, ft_printf_d, ft_printf_d,
	ft_printf_d, ft_printf_x, ft_printf_x, ft_printf_o,
	ft_printf_o, ft_printf_u, ft_printf_u, ft_printf_s,
	ft_printf_s, ft_printf_p, ft_printf_f, ft_printf_f,
	ft_printf_f, ft_printf_f, ft_printf_f, ft_printf_f,
	ft_printf_f, ft_printf_f, ft_printf_n, ft_printf_color,
	ft_printf_b};

/*
** Confirm that the match below is completely correct
*/

static int8_t	check(const char **fmt, int i)
{
	if (ft_strnstr(*fmt, g_tbl[i], LEN2) != NULL)
		return (1);
	return (0);
}

/*
** Increment through the Jump Table to find the appropriate
** function. Reset the counter if a type is not reached.
*/

static int		choosetype(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	int i;
	int	len;

	i = -1;
	while (i < LEN1 && **fmt)
	{
		i++;
		if ((**fmt == g_tbl[i][0]) && ((check(fmt, i)) == 1))
		{
			CHK((len = g_func[i](ret, fmt, x, clone)) == -1, -1);
			if (i < TYPEFIELD)
				i = -1;
			if (len > 0)
				return (len);
		}
	}
	CHK(**fmt == 0, 0);
	CHK((ft_arr_init(&x->extra, 5)) == -1, -1);
	ft_arr_appendn(&x->extra, *fmt, 1);
	handle_width(x, 'c');
	return (ft_printf_append(ret, fmt, x));
}

/*
** Increment through the format string. As soon as percentage is reached
** move to function above and look for appropriate function in Jump Table.
*/

int				ft_printf_dispatch(char **final, const char *fmt, va_list clone)
{
	size_t				i;
	t_printf_arr		ret;
	t_printf			x;

	CHK((ft_arr_init(&ret, ft_strlen(fmt) + 20)) == -1, -1);
	CHK((ft_printf_init(&x)) == -1, -1);
	CHK(*fmt == 0, 0);
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '%' && fmt[i] != 0)
			i++;
		ft_arr_appendn(&ret, (char*)fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0)
				break ;
			choosetype(&ret, &fmt, &x, clone);
		}
		CHK((ft_printf_init(&x)) == -1, -1);
	}
	*final = ft_arrtostr(&ret);
	return (ret.len);
}
