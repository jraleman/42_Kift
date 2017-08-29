/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 01:25:08 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:25:14 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			btree_apply_inorder(t_btree *root, void (*applyf)(int))
{
	t_btree		*node;

	node = root;
	if (!node)
		return ;
	if (node->left == 0 && node->right == 0)
		applyf(node->item);
	else
	{
		btree_apply_inorder(node->left, applyf);
		applyf(node->item);
		btree_apply_inorder(node->right, applyf);
	}
}
