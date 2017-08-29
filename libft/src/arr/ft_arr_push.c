/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:02:44 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 14:03:23 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		arr_push(t_arr *array, void *el)
{
	array->contents[array->end] = el;
	array->end++;
	if (ARR_END(array) >= ARR_MAX(array))
		return (arr_expand(array));
	else
		return (0);
}
