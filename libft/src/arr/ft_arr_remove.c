/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:57:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 14:06:43 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*arr_remove(t_arr *array, int i)
{
	void *elm;

	CHECK(i > array->max, RETURN(NULL), "arr attempt to get past max");
	elm = array->contents[i];
	array->contents[i] = NULL;
	return (elm);
}
