/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 09:27:38 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 10:10:17 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_itoa(intmax_t n)
{
	int8_t		len;
	uintmax_t	n_cpy;
	char		*ret;
	int8_t		ngv_flag;

	len = ft_nbrlen(n);
	ngv_flag = (n < 0) ? 1 : 0;
	n_cpy = (ngv_flag == 1) ? -n : n;
	CHK((ret = ft_strnew(len)) == NULL, NULL);
	while (--len)
	{
		ret[len] = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	ret[len] = ngv_flag ? '-' : n_cpy % 10 + '0';
	return (ret);
}
