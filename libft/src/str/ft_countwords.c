/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 22:29:24 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/21 16:51:48 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_countwords(char const *src, char c)
{
	int		i;
	int		wrd_flag;

	CHK(src == 0 || *src == 0, 0);
	wrd_flag = 0;
	i = 0;
	while (*src)
	{
		if (*src == c)
			wrd_flag = 0;
		else
		{
			if (wrd_flag == 0)
				++i;
			wrd_flag = 1;
		}
		++src;
	}
	return (i);
}
