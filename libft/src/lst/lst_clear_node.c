/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:56:04 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 16:52:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_clear_node(t_list *node, void (*del)(void *))
{
	if (!node)
		return ;
	if (del)
		(*del)(node->content);
	free(node);
}
