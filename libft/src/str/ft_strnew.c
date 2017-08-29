/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:29:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:29:41 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tmp;
	char	*tmp_orig;

	size++;
	tmp = (char*)malloc(sizeof(char) * size);
	if (!tmp)
		return (NULL);
	tmp_orig = tmp;
	while (size--)
		*tmp++ = 0;
	return (tmp_orig);
}
