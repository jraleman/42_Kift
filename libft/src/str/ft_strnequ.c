/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:32:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:32:16 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strnequ(char const *src1, char const *src2, size_t len)
{
	CHK(src1 == 0 || src2 == 0, 0);
	while ((*src1 || *src2) && len > 0)
	{
		if (*src1 != *src2)
			return (0);
		src1++;
		src2++;
		len--;
	}
	return (1);
}
