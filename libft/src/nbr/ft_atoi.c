/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:07:02 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 09:57:01 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int					neg_flag;
	unsigned long long	res;
	int					i;

	i = 0;
	res = 0;
	while (ISSPACE(*str))
		str++;
	neg_flag = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (ISDIGIT(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i > 19 || res > 9223372036854775807)
		return ((neg_flag == 1) ? -1 : 0);
	return (neg_flag * (int)res);
}
