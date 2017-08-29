/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:26:02 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:26:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *src, const char *to_find)
{
	int			len;

	if (!*to_find)
		return ((char*)src);
	while (*src)
	{
		len = 0;
		while (*src == *to_find)
		{
			to_find++;
			src++;
			len++;
			if (!*to_find)
				return ((char *)(src - len));
		}
		src = src - len;
		to_find = to_find - len;
		src++;
	}
	return (NULL);
}
