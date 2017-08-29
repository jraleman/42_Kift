/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:26:00 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:09:37 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!*alst || !alst)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
