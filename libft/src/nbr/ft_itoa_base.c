/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 09:05:08 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/03 23:31:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base(uintmax_t n, int8_t base, const char *spec)
{
	int8_t		len;
	char		*ret;

	if (base < 2)
		return (0);
	len = ft_nbrlen_base(n, base);
	CHK((ret = ft_strnew(len)) == NULL, NULL);
	while (--len)
	{
		ret[len] = spec[n % base];
		n /= base;
	}
	ret[len] = spec[n % base];
	return (ret);
}
