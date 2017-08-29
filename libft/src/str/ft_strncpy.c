/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:29:14 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:32:59 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cdst;

	cdst = dst;
	while (*src && len > 0)
	{
		*cdst++ = *src++;
		len--;
	}
	while (len-- > 0)
		*cdst++ = '\0';
	return (dst);
}
