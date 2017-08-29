/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:44:28 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:24:33 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			btree_add_node(t_btree **root, t_btree *node)
{
	t_btree		*temp;

	temp = *root;
	if (temp == NULL)
	{
		temp = node;
		*root = temp;
	}
	else if (node->item < temp->item)
		btree_add_node(&(temp->left), node);
	else if (node->item > temp->item)
		btree_add_node(&(temp->right), node);
}
