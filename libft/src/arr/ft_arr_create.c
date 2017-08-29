/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:58:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 13:59:01 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_arr	*arr_create(size_t element_size, size_t initial_max)
{
	t_arr *array;

	array = ft_memalloc(sizeof(t_arr));
	CHECK_MEM(array, RETURN(NULL));
	array->max = initial_max;
	CHECK1(array->max <= 0, free(array),
			RETURN(NULL), "You must set an initial_max > 0.");
	array->contents = ft_memalloc(sizeof(void *) * initial_max);
	CHECK_MEM1(array->contents, free(array), RETURN(NULL));
	array->end = 0;
	array->element_size = element_size;
	array->expand_rate = DEFAULT_EXPAND_RATE;
	return (array);
}
