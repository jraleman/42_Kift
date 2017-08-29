/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 01:04:13 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:24:44 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			btree_apply_postorder(t_btree *root, void (*applyf)(int))
{
	t_btree		*node;

	node = root;
	if (!node)
		return ;
	if (node->left == 0 && node->right == 0)
		applyf(node->item);
	else
	{
		btree_apply_postorder(node->left, applyf);
		btree_apply_postorder(node->right, applyf);
		applyf(node->item);
	}
}
