/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:40:57 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:32:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

t_node	*lst_new_node(void *content)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	return (node);
}
