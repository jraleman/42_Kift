/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:19:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:24:13 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *src, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*msrc;

	ch = (unsigned char)c;
	msrc = (unsigned char*)src;
	while (len-- > 0)
		*msrc++ = ch;
	return (src);
}
