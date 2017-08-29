/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:54:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/18 13:54:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		arr_clear(t_arr *array)
{
	int		i;

	i = 0;
	if (array->element_size > 0)
	{
		while (i < array->max)
		{
			if (array->contents[i] != NULL)
				free(array->contents[i]);
			++i;
		}
	}
}

void		arr_destroy(t_arr *array)
{
	if (array)
	{
		if (array->contents)
			free(array->contents);
		free(array);
	}
}

void		arr_del(t_arr *src)
{
	int		i;

	if (src == 0)
		return ;
	if (src->max > 0)
	{
		if (src->del != 0)
		{
			i = -1;
			while (++i < src->end)
			{
				if (src->contents[i] != NULL)
				{
					src->del(src->contents[i]);
					free(src->contents[i]);
				}
			}
		}
	}
	free(src->contents);
	ft_bzero(src, sizeof(t_arr));
	free(src);
}

void		arr_clear_destroy(t_arr *array)
{
	arr_clear(array);
	arr_destroy(array);
}
