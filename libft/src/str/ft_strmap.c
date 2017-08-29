/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:31:02 by jkalia            #+#    #+#             */
/*   Updated: 2017/02/27 11:31:06 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *src, char (*f)(char))
{
	size_t	len;
	int		i;
	char	*res;

	CHK(!src, 0);
	i = 0;
	len = ft_strlen(src);
	CHK((res = ft_strnew(len)) == NULL, 0);
	while (src[i])
	{
		res[i] = f(src[i]);
		i++;
	}
	return (res);
}
