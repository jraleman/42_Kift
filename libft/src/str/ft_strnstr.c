/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:30:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:31:18 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	int			len;
	const char	*limit;

	limit = src + n;
	if (!*to_find)
		return ((char*)src);
	while (*src && src < limit)
	{
		len = 0;
		while (*src == *to_find && src < limit)
		{
			to_find++;
			src++;
			len++;
			if (!*to_find)
				return ((char *)(src - len));
		}
		src -= len;
		to_find -= len;
		src++;
	}
	return (NULL);
}
