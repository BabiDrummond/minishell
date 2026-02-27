/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:53:23 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 17:17:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_del_node(t_list **head, t_list *node, void (*del)(void *))
{	
	if (!head || !*head || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->prev = NULL;
	node->next = NULL;
	lst_clear_node(node, (*del));
}
