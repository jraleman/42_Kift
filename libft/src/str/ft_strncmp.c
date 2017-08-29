/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:32:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:32:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		ft_strncmp(const char *src1, const char *src2, size_t len)
{
	CHK(len == 0, 0);
	while ((*src1 == *src2) && len)
	{
		len--;
		if (*src1 == '\0')
			return (0);
		if (len == 0)
			return (0);
		src1++;
		src2++;
	}
	return ((unsigned char)*src1 - (unsigned char)*src2);
}
