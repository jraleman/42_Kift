/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:19:11 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 12:12:10 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	const unsigned char		*csrc;
	unsigned char			*cdst;

	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (len-- > 0)
		*cdst++ = *csrc++;
	return (dst);
}
