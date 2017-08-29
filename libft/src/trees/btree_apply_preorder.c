/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_preorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 23:52:29 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:27:44 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			btree_apply_preorder(t_btree *root, void (*applyf)(int))
{
	t_btree		*node;

	node = root;
	if (node)
	{
		applyf(node->item);
		btree_apply_preorder(node->left, applyf);
		btree_apply_preorder(node->right, applyf);
	}
	else
		return ;
}
