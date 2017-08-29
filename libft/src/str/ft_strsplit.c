/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:26:38 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/21 22:30:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*each_block(char const *src, char c)
{
	int		len;
	int		i;
	char	*ret;

	len = 0;
	i = 0;
	while (src[len] != c && src[len])
		++len;
	CHK((ret = (char*)malloc(sizeof(char) * (len + 1))) == 0, 0);
	while (i < len)
	{
		ret[i] = src[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_strsplit(char const *src, char c)
{
	int		num_b;
	int		i;
	char	**ret;
	int		wrd_flag;

	CHK(src == NULL, 0);
	i = 0;
	wrd_flag = 0;
	num_b = ft_countwords(src, c);
	CHK((ret = (char**)ft_memalloc(sizeof(char*) * (num_b + 1))) == 0, 0);
	while (*src)
	{
		if (*src == c)
			wrd_flag = 0;
		else
		{
			if (wrd_flag == 0)
				CHK1((ret[i++] = each_block(src, c)) == 0, ft_tbldel(ret), 0);
			wrd_flag = 1;
		}
		++src;
	}
	return (ret);
}
