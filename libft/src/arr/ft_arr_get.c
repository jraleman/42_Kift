/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:57:17 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/01 13:58:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*arr_get(t_arr *array, int i)
{
	CHECK(i > array->max, RETURN(NULL), "arr attempt to get past max");
	return (array->contents[i]);
}
