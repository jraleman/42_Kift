/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:23:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/23 20:41:41 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int src_c, size_t len)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	unsigned char		ch;

	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	ch = (unsigned char)src_c;
	while (len-- > 0)
	{
		if ((*cdst++ = *csrc++) == ch)
			return ((void *)cdst);
	}
	return (0);
}
