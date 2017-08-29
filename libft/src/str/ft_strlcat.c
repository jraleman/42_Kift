/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:41:16 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:41:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	orig;
	size_t	len_final;

	orig = size + ft_strlen(src);
	len_final = 0;
	while (*dst && size > 0)
	{
		dst++;
		size--;
		len_final++;
	}
	if (size < 1)
		return (orig);
	while (*src && --size > 0)
	{
		*dst++ = *src++;
		len_final++;
	}
	while (*src++)
		len_final++;
	*dst = '\0';
	return (len_final);
}
