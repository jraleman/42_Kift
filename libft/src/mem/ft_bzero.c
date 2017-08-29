/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/02/27 11:08:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *src, size_t len)
{
	unsigned char	*tmp_src;

	tmp_src = (unsigned char*)src;
	while (len-- > 0)
		*tmp_src++ = 0;
}
