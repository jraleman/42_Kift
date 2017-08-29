/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:55:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 14:01:52 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*arr_new(t_arr *array)
{
	CHECK(array->element_size <= 0,
			RETURN(NULL), "Can't use arr_new on 0 size arrs.");
	return (ft_memalloc(array->element_size * 1));
}
