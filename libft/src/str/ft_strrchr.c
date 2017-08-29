/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:42:10 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:42:21 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *src, int c)
{
	char	to_find;
	char	*csrc;

	csrc = (char *)src;
	to_find = (char)c;
	while (*csrc != '\0')
		csrc++;
	if (to_find == '\0')
		return (csrc);
	while (csrc != src && *csrc != to_find)
		csrc--;
	if (*csrc == to_find)
		return (csrc);
	return (NULL);
}
