/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:46:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:30:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
