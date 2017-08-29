/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 08:59:28 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:10:24 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *src, size_t content_size)
{
	t_list	*new;

	CHK((new = (t_list*)malloc(sizeof(t_list))) == NULL, NULL);
	if (!src)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		CHK1((new->content = malloc(sizeof(content_size))) == NULL,
				free(new), NULL);
		ft_memcpy(new->content, src, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
