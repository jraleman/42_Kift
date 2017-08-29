/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:19:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/17 15:56:05 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*ret;

	CHK(size == 0, 0);
	CHK((ret = malloc(size)) == 0, 0);
	ft_bzero(ret, size);
	return (ret);
}
