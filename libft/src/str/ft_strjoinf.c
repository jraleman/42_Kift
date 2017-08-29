/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:37:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/30 07:50:18 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	strfree(char *s1, char *s2, size_t d)
{
	if (d == 0)
		return (0);
	if (d == 1)
		ft_strdel(&s1);
	else if (d == 2)
		ft_strdel(&s2);
	else if (d == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (0);
}

char		*ft_strjoinf(char *src1, char *src2, size_t d)
{
	char	*ret;
	char	*dst;
	char	*s1;
	char	*s2;
	size_t	len;

	s1 = src1;
	s2 = src2;
	CHK(src1 == 0 || src2 == 0, 0);
	len = ft_strlen(src1);
	len += ft_strlen(src2);
	CHK((dst = ft_strnew(len)) == 0, NULL);
	ret = dst;
	while (*src1)
		*dst++ = *src1++;
	while (*src2)
		*dst++ = *src2++;
	*dst = 0;
	strfree(s1, s2, d);
	return (ret);
}
