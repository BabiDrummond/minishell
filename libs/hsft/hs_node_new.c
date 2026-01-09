/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:46:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/10/01 22:50:11 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"
#include "hsft.h"

t_hsnode	*hsnode_new(void *content)
{
	t_hsnode	*node;

	node = ft_calloc(1, sizeof(t_hsnode));
	if (!node)
		return (NULL);
	node->key = content;
	return (node);
}
