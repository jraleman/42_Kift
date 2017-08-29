/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:57:12 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 14:06:25 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		arr_set(t_arr *array, int i, void *el)
{
	CHECK(i > array->max, RETURN(-1), "arr attempt to set past max");
	if (i > array->end)
		array->end = i;
	array->contents[i] = el;
	return (0);
}
