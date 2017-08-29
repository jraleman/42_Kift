/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:02:48 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 14:03:10 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*arr_pop(t_arr *array)
{
	void	*el;

	CHECK(array->end - 1 >= 0, RETURN(NULL),
			"Attempt to pop from empty array.");
	el = arr_remove(array, array->end - 1);
	array->end--;
	if (ARR_END(array) > (int)array->expand_rate
			&& ARR_END(array) % array->expand_rate)
	{
		arr_contract(array);
	}
	return (el);
}
