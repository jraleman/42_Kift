/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:52:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:25:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *src, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	CHK(!src, 0);
	i = 0;
	CHK((sub = ft_strnew(len)) == NULL, NULL);
	while (len-- > 0)
		sub[i++] = src[start++];
	return (sub);
}
