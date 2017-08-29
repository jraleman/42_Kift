/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:52:14 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/22 15:48:48 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *src, size_t srcsize, size_t newsize)
{
	void	*dst;

	if (newsize == 0)
	{
		if (src)
			free(src);
		return (src);
	}
	CHK(!src, malloc(newsize));
	CHK(newsize <= srcsize, src);
	dst = malloc(newsize);
	if (dst)
	{
		ft_memcpy(dst, src, srcsize);
		free(src);
	}
	return (dst);
}
