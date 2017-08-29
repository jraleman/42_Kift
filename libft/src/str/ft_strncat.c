/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:30:26 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:35:58 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*orig;

	orig = dst;
	while (*dst)
		dst++;
	len++;
	while (*src && --len > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (orig);
}
