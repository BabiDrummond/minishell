/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:39:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*lst_new(void *content)
{
	t_list	*node;

	node = (t_list *) safe_calloc(1, sizeof(t_list));
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
