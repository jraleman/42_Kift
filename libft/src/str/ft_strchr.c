/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:43:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:43:55 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *src, int c)
{
	unsigned char	to_find;

	to_find = (unsigned char)c;
	while (*src != '\0' && *src != to_find)
		src++;
	if (*src == to_find)
		return ((char *)src);
	return (NULL);
}
