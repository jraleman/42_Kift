/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:42:55 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:43:03 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(const char *src1, const char *src2)
{
	while (*src1 == *src2)
	{
		if (*src1 == '\0')
			return (0);
		src1++;
		src2++;
	}
	return ((unsigned char)*src1 - (unsigned char)*src2);
}
