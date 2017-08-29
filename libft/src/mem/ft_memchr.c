/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:17:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:20:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *src, int src_c, size_t len)
{
	const unsigned char		*csrc;
	unsigned char			to_find;

	to_find = (unsigned char)src_c;
	csrc = (const unsigned char*)src;
	while (len-- > 0)
	{
		if (*csrc++ == to_find)
			return ((void*)(csrc - 1));
	}
	return (NULL);
}
