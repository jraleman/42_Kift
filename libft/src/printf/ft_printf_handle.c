/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:55:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 11:54:51 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** If prec is set. '0' is ignored.
*/

size_t	set_index(t_printf *x, char c)
{
	size_t	index;

	index = 0;
	index = (x->left == 1) ? x->extra.len : 0;
	index = (x->pad == '0' && ISSIGN(x->extra.ptr[index])) ? index + 1 : index;
	if ((c == 'x' || c == 'p') && x->left == 0)
	{
		if (x->pad == ' ')
			index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 0 : index;
		else
			index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 2 : 0;
	}
	if (c == 'b' && x->pad != ' ')
		index = (ft_strstr(x->extra.ptr, "0b") != NULL) ? 2 : index;
	return (index);
}

int8_t	handle_width(t_printf *x, char c)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1 && c != 'c' && c != 's' && c != '%')
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = set_index(x, c);
	if (x->space == 1 && x->zero == 1 && diff > 0)
	{
		ft_arr_insertn(&x->extra, 0, " ", 1);
		++index;
		--diff;
	}
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
		free(tmp);
	}
	if (x->space == 1 && (x->width < x->prec) && !ft_strchr(x->extra.ptr, ' '))
		ft_arr_insertn(&x->extra, 0, " ", 1);
	return (0);
}

int8_t	handle_prec(t_printf *x, intmax_t org)
{
	char	*tmp;
	int		diff;
	int		index;

	if (x->is_prec == 0 && x->prec == 0)
		return (0);
	if (x->prec < (int)x->extra.len)
		return (0);
	diff = (org >= 0) ? x->prec - x->extra.len : x->prec - x->extra.len + 1;
	index = (org >= 0) ? 0 : 1;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, 0);
		ft_memset(tmp, '0', diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
	}
	return (0);
}

char	g_colors[34][2][15] = {
	{"{red}", "\033[31m"},
	{"{bred}", "\033[31;1m"},
	{"{green}", "\033[32m"},
	{"{bgreen}", "\033[32;1m"},
	{"{yellow}", "\033[33m"},
	{"{byellow}", "\033[33;1m"},
	{"{blue}", "\033[34m"},
	{"{bblue}", "\033[34;1m"},
	{"{purple}", "\033[35m"},
	{"{bpurple}", "\033[35;1m"},
	{"{cyan}", "\033[36m"},
	{"{bcyan}", "\033[36;1m"},
	{"{black}", "\033[30m"},
	{"{bblack}", "\033[30;1m"},
	{"{white}", "\033[37m"},
	{"{bwhite}", "\033[37;1m"},
	{"{b_red}", "\033[41m"},
	{"{b_bred}", "\033[41;1m"},
	{"{b_green}", "\033[42m"},
	{"{b_bgreen}", "\033[42;1m"},
	{"{b_yellow}", "\033[43m"},
	{"{b_byellow}", "\033[43;1m"},
	{"{b_blue}", "\033[44m"},
	{"{b_bblue}", "\033[44;1m"},
	{"{b_purple}", "\033[45m"},
	{"{b_bpurple}", "\033[45;1m"},
	{"{b_cyan}", "\033[46m"},
	{"{b_bcyan}", "\033[46;1m"},
	{"{b_black}", "\033[40m"},
	{"{b_bblack}", "\033[40;1m"},
	{"{b_white}", "\033[47m"},
	{"{b_bwhite}", "\033[47;1m"},
	{"{eoc}", "\033[0m"},
	{"{noc}", "\033[0m"}};

int8_t	ft_printf_color(t_printf_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	int	i;

	i = 0;
	(void)clone;
	CHK1((ft_arr_init(&x->extra, 10)) == -1, ft_arr_del(ret), -1);
	while (i < 34)
	{
		if (ft_strnstr(*fmt, g_colors[i][0], ft_strlen(g_colors[i][0])) != 0)
		{
			ft_arr_appendn(&x->extra, g_colors[i][1],
					sizeof(char) * ft_strlen(g_colors[i][1]));
			*fmt = *fmt + ft_strlen(g_colors[i][0]) - 1;
			return (ft_printf_append(ret, fmt, x));
		}
		++i;
	}
	return (0);
}
