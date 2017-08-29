/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:36:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/02 14:38:41 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *cnt))
{
	t_list	*ret;
	t_list	*org;

	org = f(lst);
	ret = org;
	while (lst->next)
	{
		ret->next = f(lst->next);
		ret = ret->next;
		lst = lst->next;
	}
	return (org);
}
