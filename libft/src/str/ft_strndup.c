/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:29:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:33:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t len)
{
	char		*dst;
	char		*cdst;

	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	cdst = dst;
	len++;
	while (--len > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (cdst);
}
