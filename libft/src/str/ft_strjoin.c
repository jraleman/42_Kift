/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:50:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:45:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *src1, char const *src2)
{
	char	*ret;
	char	*dst;
	size_t	len;

	CHK(src1 == 0 || src2 == 0, 0);
	len = ft_strlen(src1);
	len += ft_strlen(src2);
	CHK((dst = ft_strnew(len + 1)) == 0, NULL);
	ret = dst;
	while (*src1)
		*dst++ = *src1++;
	while (*src2)
		*dst++ = *src2++;
	*dst = '\0';
	return (ret);
}
