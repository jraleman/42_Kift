/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:23:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:23:33 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *src1, const void *src2, size_t len)
{
	const unsigned char	*csrc1;
	const unsigned char	*csrc2;

	csrc1 = (unsigned char*)src1;
	csrc2 = (unsigned char*)src2;
	while (len-- > 0)
	{
		if (*csrc1 != *csrc2)
			return ((unsigned char)*csrc1 - (unsigned char)*csrc2);
		csrc1++;
		csrc2++;
	}
	return (0);
}
