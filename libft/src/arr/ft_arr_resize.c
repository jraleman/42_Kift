/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:54:11 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/22 15:45:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		arr_resize(t_arr *array, size_t newsize)
{
	void	*contents;

	CHECK(newsize < 0, RETURN(-1), "The newsize must be > 0.");
	contents = ft_realloc(array->contents, array->max * sizeof(void *),
			newsize * sizeof(void *));
	CHECK_MEM(contents, RETURN(-1));
	array->contents = contents;
	array->max = newsize;
	return (0);
}

int		arr_expand(t_arr *array)
{
	size_t	old_max;
	int		chk;

	old_max = array->max;
	chk = arr_resize(array, array->max + array->expand_rate);
	CHECK(chk == -1, RETURN(-1), "Failed to expand array to new size: %d",
			array->max + (int)array->expand_rate);
	ft_memset(array->contents + old_max, 0, array->expand_rate + 1);
	return (0);
}

int		arr_contract(t_arr *array)
{
	int new_size;

	new_size = array->end < (int)array->expand_rate ?
		(int)array->expand_rate : array->end;
	return (arr_resize(array, new_size + 1));
}
