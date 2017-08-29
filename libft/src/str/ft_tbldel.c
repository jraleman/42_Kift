/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tbldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:30:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/22 15:30:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_tbldel(char **tbl)
{
	size_t	i;

	i = 0;
	if (tbl == 0 || *tbl == 0)
		return ;
	while (tbl[i])
	{
		free(tbl[i]);
		++i;
	}
	free(tbl);
	tbl = NULL;
}
