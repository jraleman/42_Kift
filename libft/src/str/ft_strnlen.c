/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:31:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:31:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strnlen(const char *src, size_t maxlen)
{
	size_t len;

	len = 0;
	while (*src && maxlen > 0)
	{
		src++;
		len++;
		maxlen--;
	}
	return (len);
}
