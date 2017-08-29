/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:22:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:24:49 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	unsigned char		*final;

	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	final = cdst;
	if (cdst > csrc)
	{
		csrc = csrc + len - 1;
		cdst = cdst + len - 1;
		while (len-- > 0)
			*cdst-- = *csrc--;
	}
	else
	{
		while (len-- > 0)
			*cdst++ = *csrc++;
	}
	return (final);
}
