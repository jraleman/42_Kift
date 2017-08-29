/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:53:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/02/27 15:53:23 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*res;

	CHK(!src, 0);
	len = ft_strlen(src);
	i = 0;
	CHK((res = ft_strnew(len)) == NULL, 0);
	while (src[i])
	{
		res[i] = f(i, src[i]);
		i++;
	}
	return (res);
}
